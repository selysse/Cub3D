/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_hit_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:43:46 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/25 18:33:41 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_point			inter_h(float ray_angle, t_all *game)
{
	t_point			i;
	t_point			player;

	player = game->player.coord;
	i.y = floor(player.y);
	if ((ray_angle > 0) && (ray_angle < M_PI))
		i.y += 1.0;
	i.x = player.x + ((i.y - player.y) / tan(ray_angle));
	return (i);
}

static void				wall_h(float ray_angle, t_point *step)
{
	if (!((ray_angle > 0) && (ray_angle < M_PI)))
		step->y *= -1.0;
	step->x = 1.0 / tan(ray_angle);
	if ((!(ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI) && step->x > 0.0)\
	|| ((ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI) && step->x < 0.0))
		step->x *= -1.0;
}

t_point					wall_hit_h(float ray_angle, t_all *game)
{
	t_point			inter;
	t_point			step;
	t_point			next_touch;
	t_point			to_check;
	t_point			no_point;

	no_point.x = -1;
	no_point.y = -1;
	step.y = 1.0;
	inter = inter_h(ray_angle, game);
	wall_h(ray_angle, &step);
	points(&next_touch, &inter);
	while (next_touch.x >= 0.0 && next_touch.x <= game->win.width
		&& next_touch.y >= 0.0 && next_touch.y <= game->win.height)
	{
		points(&to_check, &next_touch);
		if (!((ray_angle > 0) && (ray_angle < M_PI)))
			to_check.y -= 1.0;
		if (is_wall_at(game, to_check))
			return (next_touch);
		next_touch.x += step.x;
		next_touch.y += step.y;
	}
	return (no_point);
}
