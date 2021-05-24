/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:38:20 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/24 19:03:27 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				free_list(void *data)
{
	free(data);
	data = NULL;
}

void				free_tab(char **tab)
{
	if (tab)
	{
		while (*tab)
		{
			free(*tab);
			tab++;
		}
		tab = NULL;
	}
}

void				free_map(t_map *map)
{
	unsigned int		i;

	i = 0;
	while (i < map->num_rows)
	{
		free(map->tab[i]);
		i++;
	}
	free(map->tab);
	map->tab = NULL;
}

void				free_texture(t_win *win, t_texture texture[5])
{
	int				i;

	i = 0;
	while (i < 5)
	{
		if (texture[i].file)
			free(texture[i].file);
		if (win->mlx_ptr && texture[i].tex_ptr)
		{
			mlx_destroy_image(win->mlx_ptr, texture[i].tex_ptr);
			texture[i].tex_ptr = NULL;
			texture[i].data = NULL;
		}
		i++;
	}
}

void				free_full(t_all *game)
{
	if (game->tab_rays)
		free(game->tab_rays);
	free_sprite(game);
	free_texture(&game->win, game->tex);
	free_map(&game->map);
	if (game->win.mlx_ptr)
	{
		if (game->win.win_ptr)
		{
			if (game->win.image.img)
			{
				mlx_destroy_image(game->win.mlx_ptr, game->win.image.img);
				game->win.image.img = NULL;
				game->win.image.addr = NULL;
			}
			mlx_destroy_window(game->win.mlx_ptr, game->win.win_ptr);
		}
		mlx_destroy_display(game->win.mlx_ptr);
		free(game->win.mlx_ptr);
	}
	game->win.mlx_ptr = NULL;
}
