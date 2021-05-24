/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:38:20 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/24 20:31:05 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		elem(t_map *map)
{
	unsigned int		i;
	unsigned int		j;
	char				tmp;

	i = 0;
	while (i < map->num_rows)
	{
		j = 1;
		while (j < map->num_cols)
		{
			tmp = map->tab[i][j];
			if (tmp != '0' && tmp != '1' && tmp != '2' && tmp != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int		border_lr(t_map *map)
{
	unsigned int		i;

	i = 0;
	while (i < map->num_rows)
	{
		if ((map->tab[i][0] != ' ' && map->tab[i][0] != '1') ||
			(map->tab[i][map->num_cols - 1] != ' ' &&
			map->tab[i][map->num_cols - 1] != '1'))
			return (0);
		i++;
	}
	return (1);
}

static int		border_td(t_map *map)
{
	unsigned int		j;

	j = 0;
	while (j < map->num_cols)
	{
		if ((map->tab[0][j] != ' ' && map->tab[0][j] != '1') ||
			(map->tab[map->num_rows - 1][j] != ' ' &&
			map->tab[map->num_rows - 1][j] != '1'))
			return (0);
		j++;
	}
	return (1);
}

static int		check_space(t_map *map)
{
	unsigned int		i;
	unsigned int		j;

	i = 1;
	while (i < map->num_rows - 1)
	{
		j = 1;
		while (j < map->num_cols - 1)
		{
			if (map->tab[i][j] == '0')
			{
				if (map->tab[i - 1][j] == ' ' || map->tab[i + 1][j] == ' '
					|| map->tab[i][j - 1] == ' ' || map->tab[i][j + 1] == ' '
					|| map->tab[i - 1][j - 1] == ' ' ||
					map->tab[i - 1][j + 1] == ' '
					|| map->tab[i + 1][j - 1] == ' ' ||
					map->tab[i + 1][j + 1] == ' ')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int				valid_map(t_all *game)
{
	if (!valid_player_pos(game))
		return (0);
	if (!elem(&game->map))
	{
		printf("%s", "Bad caractere in map.\n");
		return (0);
	}
	if (!border_lr(&game->map) ||
		!border_td(&game->map) || !check_space(&game->map))
	{
		printf("%s", "Map isn't surrounded by walls.\n");
		return (0);
	}
	if (valid_sprites(game))
		return (1);
	return (0);
}
