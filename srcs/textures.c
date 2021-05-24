/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:50:17 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/24 19:24:45 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			valid_texture(t_all *game, char *file, int nb)
{
	int				fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		if (file)
		{
			printf("%s", "Bad texture file.\n");
			return (0);
		}
		printf("%s", " File Texture is missing.\n");
		return (0);
	}
	close(fd);
	if (game->tex[nb].file)
	{
		printf("%s", "Texture specified twice.\n");
		return (0);
	}
	game->tex[nb].file = ft_strdup(file);
	return (1);
}

static int			parse_tex(t_all *game, char **tab)
{
	if (ft_strequ(*tab, "S"))
	{
		valid_texture(game, tab[1], 4);
		return (1);
	}
	return (0);
}

int					parsing_texture(t_all *game, char **tab)
{
	if (ft_strequ(*tab, "NO"))
	{
		valid_texture(game, tab[1], 0);
		return (1);
	}
	else if (ft_strequ(*tab, "SO"))
	{
		valid_texture(game, tab[1], 2);
		return (1);
	}
	else if (ft_strequ(*tab, "WE"))
	{
		valid_texture(game, tab[1], 3);
		return (1);
	}
	else if (ft_strequ(*tab, "EA"))
	{
		valid_texture(game, tab[1], 1);
		return (1);
	}
	parse_tex(game, tab);
	return (0);
}
