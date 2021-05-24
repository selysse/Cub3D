/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_hit_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:43:05 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/25 18:30:24 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_point			inter_w(float ray_angle, t_all *game)
{
	t_point			i;
	t_point			player;

	player = game->player.coord;
	i.x = floor(player.x);
	if (ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI)
		i.x += 1.0;
	i.y = player.y + (i.x - player.x) * tan(ray_angle);
	return (i);
}

void					points(t_point *dst, t_point *src)
{
	dst->x = src->x;
	dst->y = src->y;
}

static void				wall_d(float ray_angle, t_point *step)
{
	if (!(ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI))
		step->x *= -1.0;
	step->y = tan(ray_angle);
	if ((!((ray_angle > 0) && (ray_angle < M_PI))) && step->y > 0.0)
		step->y *= -1.0;
	if (((ray_angle > 0) && (ray_angle < M_PI)) && step->y < 0.0)
		step->y *= -1.0;
}

t_point					wall_hit_w(float ray_angle, t_all *game)
{
	t_point			inter;
	t_point			step;
	t_point			next_touch;
	t_point			to_check;
	t_point			no_point;

	no_point.x = -1;
	no_point.y = -1;
	step.x = 1.0;
	inter = inter_w(ray_angle, game);
	wall_d(ray_angle, &step);
	next_touch = inter;
	while (next_touch.x >= 0 && next_touch.x <= game->win.width
		&& next_touch.y >= 0 && next_touch.y <= game->win.height)
	{
		to_check = next_touch;
		if (!(ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI))
			to_check.x -= 1.0;
		if (is_wall_at(game, to_check))
			return (next_touch);
		next_touch.x += step.x;
		next_touch.y += step.y;
	}
	return (no_point);
}
