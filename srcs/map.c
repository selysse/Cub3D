/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:37:20 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/24 19:06:13 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	col_nb(t_list *list)
{
	int					len;
	int					i;

	i = 0;
	while (list)
	{
		space_ut(list->content);
		len = ft_strlen(list->content);
		if (len > 0)
		{
			if (i < len)
				i = len;
		}
		else
			return (0);
		list = list->next;
	}
	return (i);
}

static int	filling(t_all *game, t_list *list)
{
	int					i;

	i = 0;
	while (list)
	{
		game->map.tab[i] = ft_strnew(game->map.num_cols);
		ft_memset(game->map.tab[i], ' ', game->map.num_cols);
		if (game->map.tab[i])
			ft_memcpy(game->map.tab[i], list->content,
				ft_strlen(list->content));
		else
		{
			printf("%s", "Malloc fail.\n");
			return (0);
		}
		list = list->next;
		i++;
	}
	return (1);
}

int			map(t_all *game, t_list *list)
{
	int					col;
	int					row;

	col = col_nb(list);
	row = ft_lstsize(list);
	if (col == 0 || row == 0)
	{
		printf("%s", "Bad format in the map section.\n");
		return (0);
	}
	game->map.num_rows = row;
	game->map.num_cols = col;
	game->map.tab = (char **)malloc(sizeof(char *) * row);
	if (game->map.tab)
	{
		if (filling(game, list))
			return (1);
	}
	printf("%s", "Malloc fail.\n");
	return (0);
}
