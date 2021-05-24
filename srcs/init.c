/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:49:24 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/25 18:47:24 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void				init_win(t_win *win)
{
	win->mlx_ptr = NULL;
	win->win_ptr = NULL;
	win->width = 0;
	win->height = 0;
	win->num_rays = 0;
	win->c_color = -1;
	win->f_color = -1;
	win->image.img = NULL;
	win->image.addr = NULL;
	win->image.bits_per_pixel = 0;
	win->image.line_length = 0;
	win->image.endian = 0;
	win->image.width = 0;
	win->image.height = 0;
}

static void				init_texture(t_all *game)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		game->tex[i].tex_ptr = NULL;
		game->tex[i].data = NULL;
		game->tex[i].file = NULL;
		game->tex[i].width = 0;
		game->tex[i].height = 0;
		game->tex[i].bits_per_pixel = 0;
		game->tex[i].line_length = 0;
		game->tex[i].endian = 0;
		i++;
	}
}

void					init_all(t_all *game)
{
	init_win(&game->win);
	game->map.tab = NULL;
	game->map.num_rows = 0;
	game->map.num_cols = 0;
	game->player.coord.x = -1;
	game->player.coord.y = -1;
	game->player.turn_dir = 0;
	game->player.walk_dir = 0;
	game->player.trans_dir = 0;
	game->player.rot_angle = 0;
	init_texture(game);
	game->tab_sprite = NULL;
	game->tab_rays = NULL;
	game->count = 0;
	game->in_map = 0;
	game->dist_pr = 0.0;
}
