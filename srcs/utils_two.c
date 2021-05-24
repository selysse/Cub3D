/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:50:17 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/25 17:57:58 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				is_wall_at(t_all *game, t_point pos)
{
	unsigned int		map_grid_index_x;
	unsigned int		map_grid_index_y;

	if (pos.x < 0 || pos.x > game->win.width ||
		pos.y < 0 || pos.y > game->win.height)
		return (1);
	map_grid_index_x = floor(pos.x);
	map_grid_index_y = floor(pos.y);
	if (map_grid_index_x >= game->map.num_cols ||
		map_grid_index_y >= game->map.num_rows)
		return (1);
	return (game->map.tab[map_grid_index_y][map_grid_index_x] == '1');
}

char			type_wall(t_all *game, t_point pos)
{
	unsigned int		map_grid_index_x;
	unsigned int		map_grid_index_y;
	char				tmp;

	if (pos.x < 0)
		pos.x = pos.x * (-1);
	if (pos.y < 0)
		pos.y = pos.y * (-1);
	map_grid_index_x = floor(pos.x);
	map_grid_index_y = floor(pos.y);
	tmp = game->map.tab[map_grid_index_y][map_grid_index_x];
	return (tmp);
}

void			ft_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char		*dst;

	if (x >= 0 && x < win->width &&
		y >= 0 && y < win->height)
	{
		dst = win->image.addr + (y * win->image.line_length +
			x * (win->image.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}
