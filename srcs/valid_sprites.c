/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:54:39 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/25 18:40:46 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			nb_sprites(t_map *map)
{
	unsigned int	i;
	unsigned int	j;
	int				count;

	i = 0;
	count = 0;
	while (i < map->num_rows)
	{
		j = 0;
		while (j < map->num_cols)
		{
			if (map->tab[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void			load_sprites(t_all *game)
{
	unsigned int	i;
	unsigned int	j;
	int				nb;

	i = 0;
	nb = 0;
	while (i < game->map.num_rows)
	{
		j = 0;
		while (j < game->map.num_cols)
		{
			if (game->map.tab[i][j] == '2' && nb < game->count)
			{
				game->tab_sprite[nb].pos.x = j + 0.5;
				game->tab_sprite[nb].pos.y = i + 0.5;
				game->tab_sprite[nb].dist = -1;
				game->tab_sprite[nb].angle = 0;
				game->tab_sprite[nb].is_vis = 0;
				nb++;
			}
			j++;
		}
		i++;
	}
}

void				free_sprite(t_all *game)
{
	free(game->tab_sprite);
	game->tab_sprite = NULL;
}

int					valid_sprites(t_all *game)
{
	game->count = nb_sprites(&game->map);
	if (game->count > 0)
	{
		game->tab_sprite = (t_sprite*)malloc(sizeof(t_sprite)
			* game->count);
		if (!game->tab_sprite)
		{
			printf("%s", "Malloc fail.\n");
			return (0);
		}
		load_sprites(game);
	}
	return (1);
}
