/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:38:20 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/25 18:47:24 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int				valid_resolution(t_all *game)
{
	int			resol_x;
	int			resol_y;

	if (g_flag == 0)
	{
		mlx_get_screen_size(game->win.mlx_ptr, &resol_x, &resol_y);
		if (game->win.width > resol_x)
			game->win.width = resol_x;
		if (game->win.height > resol_y)
			game->win.height = resol_y;
	}
	game->win.num_rays = game->win.width;
	game->dist_pr = (game->win.width / 2) / tan(1.04719755 / 2);
	game->tab_rays = (t_ray *)malloc(sizeof(t_ray) * game->win.width);
	if (!game->tab_rays)
	{
		printf("%s", "Malloc fail.\n");
		return (0);
	}
	return (1);
}

static int				parsin_two(t_all *game, int resol_x, int resol_y)
{
	if (game->win.width == 0 && game->win.height == 0)
	{
		game->win.width = resol_x;
		game->win.height = resol_y;
		game->win.mlx_ptr = mlx_init();
		if (!game->win.mlx_ptr)
		{
			printf("%s", "mlx_init() fail.\n");
			return (0);
		}
	}
	return (1);
}

int						parsing_resolution(t_all *game, char **tab)
{
	int			resol_x;
	int			resol_y;

	if (tab[1] && tab[2] && is_number(tab[1]) && is_number(tab[2]))
	{
		resol_x = ft_atoi(tab[1]);
		resol_y = ft_atoi(tab[2]);
		if (resol_x > 0 && resol_y > 0)
		{
			if (parsin_two(game, resol_x, resol_y))
			{
				valid_resolution(game);
				return (1);
			}
			printf("%s", "Resolution specified twice.\n");
			return (0);
		}
		printf("%s", "Bad resolution.\n");
		return (0);
	}
	printf("%s", "Couldn't parse resolution.\n");
	return (0);
}
