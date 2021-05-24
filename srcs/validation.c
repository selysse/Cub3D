/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 01:29:03 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/24 19:12:10 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				check_file(char const *name)
{
	int		len;

	len = ft_strlen(name) - 4;
	if (len > 0)
		return (ft_strequ(&name[len], ".cub"));
	else
		return (0);
}

static int		valid_data_two(t_all *game)
{
	if (!game->tex[4].file)
	{
		printf("%s", "Texture is Sprite missing.\n");
		return (0);
	}
	if (game->win.f_color == -1 || game->win.c_color == -1)
	{
		printf("%s", "Color is missing.\n");
		return (0);
	}
	if (!game->in_map)
	{
		printf("%s", "No map !\n");
		return (0);
	}
	return (1);
}

static int		valid_data(t_all *game)
{
	if (!game->tex[0].file)
	{
		printf("%s", "Texture is North missing.\n");
		return (0);
	}
	if (!game->tex[2].file)
	{
		printf("%s", "Texture is South missing.\n");
		return (0);
	}
	if (!game->tex[1].file)
	{
		printf("%s", "Texture is East missing.\n");
		return (0);
	}
	if (!game->tex[3].file)
	{
		printf("%s", "Texture is West missing.\n");
		return (0);
	}
	if (valid_data_two(game))
		return (1);
	return (0);
}

static int		load_textures(t_all *game)
{
	int				i;

	i = 0;
	while (i < 5)
	{
		game->tex[i].tex_ptr = mlx_xpm_file_to_image(game->win.mlx_ptr,
		game->tex[i].file, &game->tex[i].width, &game->tex[i].height);
		if (game->tex[i].tex_ptr)
		{
			game->tex[i].data = mlx_get_data_addr(game->tex[i].tex_ptr,
			&game->tex[i].bits_per_pixel,
			&game->tex[i].line_length, &game->tex[i].endian);
		}
		else
		{
			printf("%s %s\n", "Bad texture file.\n", game->tex[i].file);
			return (0);
		}
		i++;
	}
	return (1);
}

int				validation(t_all *game, t_list *list, int ret)
{
	if (!ret)
	{
		ft_lstclear(&list, &free_list);
		return (0);
	}
	ret = map(game, list) && valid_map(game);
	ft_lstclear(&list, &free_list);
	if (!ret)
		return (0);
	if (game->win.width == 0 || game->win.height == 0)
	{
		printf("%s", "No resolution define.\n");
		return (0);
	}
	if (valid_data(game))
	{
		if (load_textures(game))
			return (1);
	}
	return (0);
}
