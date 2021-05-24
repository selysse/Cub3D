/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 02:38:20 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/25 18:47:24 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			show_line(t_all *game, int x, t_ray ray, float wall_height)
{
	int				i;
	int				off_x;
	int				off_y;
	int				color;

	i = 0;
	while (i < ray.top_pixel)
		ft_mlx_pixel_put(&game->win, x, i++, game->win.c_color);
	if (ray.hit_vert)
		off_x = (int)(fmod(ray.wall_hit.y, 1.0) * game->tex[ray.id].width);
	else
		off_x = (int)(fmod(ray.wall_hit.x, 1.0) * game->tex[ray.id].width);
	while (i < ray.bot_pixel)
	{
		off_y = (i + (wall_height / 2.0) - (game->win.height / 2.0)) *
		(game->tex[ray.id].height / wall_height);
		color = get_tex_color(game->tex[ray.id], off_x, off_y);
		ft_mlx_pixel_put(&game->win, x, i++, color);
	}
	while (i < game->win.height)
		ft_mlx_pixel_put(&game->win, x, i++, game->win.f_color);
}

void				gen_3d(t_all *game, t_ray *tab_rays)
{
	int				i;
	float			perp_dist;
	float			wall_height;
	int				top_pixel;
	int				bot_pixel;

	i = 0;
	while (i < game->win.num_rays)
	{
		perp_dist = tab_rays[i].dist * cos(tab_rays[i].angle -
			game->player.rot_angle);
		wall_height = game->dist_pr / perp_dist;
		top_pixel = (game->win.height / 2.0) - ((int)wall_height / 2);
		if (top_pixel < 0)
			top_pixel = 0;
		bot_pixel = (game->win.height / 2) + ((int)wall_height / 2);
		if (bot_pixel > game->win.height)
			bot_pixel = game->win.height;
		tab_rays[i].top_pixel = top_pixel;
		tab_rays[i].bot_pixel = bot_pixel;
		show_line(game, i, tab_rays[i], wall_height);
		i++;
	}
}

int					display(t_all *game)
{
	cast_rays(game);
	gen_3d(game, game->tab_rays);
	scan_sprite(game);
	if (g_flag == 0)
		mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr,
	game->win.image.img, 0, 0);
	return (1);
}
