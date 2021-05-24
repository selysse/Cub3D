/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:38:20 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/25 18:47:24 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			draw_sprite(t_all *game, t_sprite sprite, t_point pos,
					t_point off)
{
	int				color;
	int				not;

	not = get_tex_color(game->tex[4], 0, 0);
	off.y = (pos.y + (sprite.height / 2.0) - (game->win.height / 2.0)) *
	(game->tex[4].height / sprite.height);
	if (off.y < 0)
		off.y = 0;
	color = get_tex_color(game->tex[4], off.x, off.y);
	if (color != not)
		ft_mlx_pixel_put(&game->win, sprite.first_x + pos.x, pos.y, color);
}

static void			render_sprite(t_all *game, t_sprite sprite)
{
	t_point			point;
	t_point			of;
	float			dist_ray;

	point.x = -1;
	while (sprite.first_x + point.x < 0)
		point.x++;
	while (++point.x < sprite.height &&
		sprite.first_x + point.x < game->win.width)
	{
		dist_ray = game->tab_rays[(int)(sprite.first_x + point.x)].dist;
		if (dist_ray > game->tab_sprite[sprite.index].dist)
		{
			of.x = point.x * game->tex[4].width / sprite.height;
			point.y = sprite.top_pixel - 1;
			while (++point.y < sprite.bot_pixel)
				draw_sprite(game, sprite, point, of);
		}
	}
}

static void			sprite_data(t_all *game, t_sprite *sprite)
{
	int				i;
	int				top;
	int				bot;

	i = -1;
	while (++i < game->count)
	{
		if (sprite[i].is_vis)
		{
			sprite[i].index = i;
			sprite[i].height = (game->dist_pr) /
			(cos(sprite[i].angle) * sprite[i].dist);
			top = (game->win.height / 2.0) - (sprite[i].height / 2);
			if (top < 0)
				top = 0;
			bot = (game->win.height / 2.0) + (sprite[i].height / 2);
			if (bot > game->win.height)
				bot = game->win.height;
			sprite[i].top_pixel = top;
			sprite[i].bot_pixel = bot;
			sprite[i].first_x = game->dist_pr * tan(sprite[i].angle)
			+ (game->win.width / 2) - (sprite[i].height / 2);
			render_sprite(game, sprite[i]);
		}
	}
}

static void			sort_sprites(t_sprite *sprites, int nb_sprites)
{
	t_sprite		tmp;
	int				i;
	int				j;

	i = 0;
	while (i < nb_sprites)
	{
		j = i;
		while (j < nb_sprites)
		{
			if (sprites[i].dist < sprites[j].dist)
			{
				tmp = sprites[j];
				sprites[j] = sprites[i];
				sprites[i] = tmp;
				i = 0;
			}
			j++;
		}
		i++;
	}
}

int					scan_sprite(t_all *game)
{
	int				i;

	i = 0;
	while (i < game->count)
	{
		game->tab_sprite[i].dist = distance(game->player.coord,
			game->tab_sprite[i].pos);
		game->tab_sprite[i].angle = sprite_angle(game->tab_sprite[i].pos,
			game->player.coord, game->player.rot_angle);
		game->tab_sprite[i].is_vis =
		sprite_visible(game->tab_sprite[i].angle);
		i++;
	}
	sort_sprites(game->tab_sprite, game->count);
	sprite_data(game, game->tab_sprite);
	return (1);
}
