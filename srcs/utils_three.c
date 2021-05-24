/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 14:15:46 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/25 18:43:45 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float				sprite_angle(t_point sprite_pos, t_point player_pos,
		float player_rot_angle)
{
	float			dx;
	float			dy;
	float			angle;

	dx = sprite_pos.x - player_pos.x;
	dy = sprite_pos.y - player_pos.y;
	angle = atan2(dy, dx) - player_rot_angle;
	return (angle);
}

int					sprite_visible(float angle_sprite)
{
	if (angle_sprite < -M_PI)
		angle_sprite += 2 * M_PI;
	if (angle_sprite >= M_PI)
		angle_sprite -= 2 * M_PI;
	if (angle_sprite < 0)
		angle_sprite = -angle_sprite;
	return (angle_sprite < (1.04719755 / 2));
}

int					is_sprite_at(t_all *game, t_point pos)
{
	unsigned int		map_grid_index_x;
	unsigned int		map_grid_index_y;

	if (pos.x < 0 || pos.x > game->win.width ||
		pos.y < 0 || pos.y > game->win.height)
		return (0);
	map_grid_index_x = floor(pos.x);
	map_grid_index_y = floor(pos.y);
	if (map_grid_index_x >= game->map.num_cols ||
		map_grid_index_y >= game->map.num_rows)
		return (0);
	return (game->map.tab[map_grid_index_y][map_grid_index_x] == '2');
}
