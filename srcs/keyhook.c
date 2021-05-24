/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:49:24 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/24 13:03:15 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			deal_key(int key, t_all *game)
{
	if (key == KEY_ESC)
		exit_game(game);
	else if (key == KEY_RIGHT)
		game->player.turn_dir = 1;
	else if (key == KEY_LEFT)
		game->player.turn_dir = -1;
	else if (key == KEY_UP || key == KEY_A)
		game->player.walk_dir = 1;
	else if (key == KEY_DOWN || key == KEY_W)
		game->player.walk_dir = -1;
	else if (key == KEY_S)
		game->player.trans_dir = -1;
	else if (key == KEY_D)
		game->player.trans_dir = 1;
	update_player(game);
	display(game);
	return (0);
}

int			release_key(int key, t_all *game)
{
	if (key == KEY_RIGHT || key == KEY_LEFT)
		game->player.turn_dir = 0;
	else if (key == KEY_UP || key == KEY_DOWN)
		game->player.walk_dir = 0;
	else if (key == KEY_S || key == KEY_D)
		game->player.trans_dir = 0;
	return (0);
}
