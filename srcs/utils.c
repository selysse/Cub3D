/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:43:46 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/25 16:16:32 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float			distance(t_point i, t_point j)
{
	if (i.x >= 0 && j.x >= 0)
		return (sqrt((j.x - i.x) * (j.x - i.x) + (j.y - i.y) * (j.y - i.y)));
	return (FLT_MAX);
}

int				get_tex_color(t_texture txtr, int x, int y)
{
	char			*tmp;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x > txtr.width)
		x = txtr.width;
	if (y > txtr.height)
		y = txtr.height;
	tmp = txtr.data + (y * txtr.line_length + x * txtr.bits_per_pixel / 8);
	return (*(unsigned int*)tmp);
}

int				is_texture(char **tab_line)
{
	if (ft_strequ(*tab_line, "NO") || ft_strequ(*tab_line, "SO")
		|| ft_strequ(*tab_line, "WE") || ft_strequ(*tab_line, "EA")
		|| ft_strequ(*tab_line, "S"))
		return (1);
	else
		return (0);
}

int				get_pixel_color(t_image img, int x, int y)
{
	char			*dst;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x > img.width)
		x = img.width;
	if (y > img.height)
		y = img.height;
	dst = img.addr + (y * img.line_length + x * img.bits_per_pixel / 8);
	return (*(unsigned int*)dst);
}
