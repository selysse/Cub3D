/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:38:20 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/24 20:20:55 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		valid_color(int color)
{
	return (color >= 0 && color <= 255);
}

int				parsing_color(const char *str)
{
	char		**rgb;
	int			color_tab[3];
	int			color;
	int			i;

	i = -1;
	rgb = ft_split(str, ',');
	while (++i < 3)
	{
		if (rgb[i] && is_number(rgb[i]) && valid_color(ft_atoi(rgb[i])))
			color_tab[i] = ft_atoi(rgb[i]);
		else
		{
			free_tab(rgb);
			free(rgb);
			printf("%s", "Invalid floor/ceiling line.\n");
			return (-1);
		}
	}
	color = (0x0 << 24 | color_tab[0] << 16 | color_tab[1] << 8 | color_tab[2]);
	free_tab(rgb);
	free(rgb);
	return (color);
}

int				color(t_all *game, char **tab)
{
	int			color;

	if (tab[1] && tab[1][0] != '\0')
	{
		color = parsing_color(tab[1]);
		if (color == -1)
			return (0);
	}
	else
	{
		printf("%s", "Bad color.\n");
		return (0);
	}
	if (ft_strequ(tab[0], "F"))
		game->win.f_color = color;
	else
		game->win.c_color = color;
	return (1);
}
