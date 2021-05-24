/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:49:24 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/25 17:38:18 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			valid_pos_player(t_all *game, int x, int y, char dir)
{
	if (game->player.coord.x == -1 && game->player.coord.y == -1)
	{
		game->player.coord.x = (float)x + 0.5;
		game->player.coord.y = (float)y + 0.5;
		if (dir == 'E')
			game->player.rot_angle = 0;
		else if (dir == 'S')
			game->player.rot_angle = M_PI / 2;
		else if (dir == 'W')
			game->player.rot_angle = M_PI;
		else
			game->player.rot_angle = 1.5 * M_PI;
		return (1);
	}
	printf("%s", "Duplicate player position.\n");
	return (0);
}

static int			no_player(t_all *game)
{
	if (game->player.coord.x == -1)
	{
		printf("%s", "No player position.\n");
		return (0);
	}
	return (1);
}

int					valid_player_pos(t_all *game)
{
	unsigned int	x;
	unsigned int	y;
	int				ret;

	y = 0;
	ret = FALSE;
	while (y < game->map.num_rows)
	{
		x = 0;
		while (x < game->map.num_cols)
		{
			if (ft_strchr("NSEW", game->map.tab[y][x]))
			{
				ret = valid_pos_player(game, x, y, game->map.tab[y][x]);
				game->map.tab[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	no_player(game);
	return (ret);
}

void				update_player(t_all *game)
{
	float			step;
	float			ang;
	t_point			new;

	game->player.rot_angle += game->player.turn_dir * (3 * (M_PI / 180));
	game->player.rot_angle = fmod(game->player.rot_angle, (2 * M_PI));
	while (game->player.rot_angle < 0)
		game->player.rot_angle += 2 * M_PI;
	if (game->player.trans_dir != 0)
	{
		ang = game->player.rot_angle + ((M_PI / 2) * game->player.trans_dir);
		new.x = game->player.coord.x + cos(ang) * 0.3;
		new.y = game->player.coord.y + sin(ang) * 0.3;
	}
	else
	{
		step = game->player.walk_dir * 0.3;
		new.x = game->player.coord.x + cos(game->player.rot_angle) * step;
		new.y = game->player.coord.y + sin(game->player.rot_angle) * step;
	}
	if (!is_wall_at(game, new) && !is_sprite_at(game, new))
		game->player.coord = new;
}
