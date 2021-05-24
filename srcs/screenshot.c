/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:19:31 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/24 19:08:15 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			screenshot_data(t_image img, int width, int height, int fd)
{
	int				i;
	int				j;
	char			*tmp;

	i = height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < width)
		{
			tmp = img.addr + (i * img.line_length + j * img.bits_per_pixel / 8);
			write(fd, tmp, 4);
			j++;
		}
		i--;
	}
}

static void			screenshot_info(t_all *game, int fd)
{
	int				i;
	unsigned char	info[40];

	i = 0;
	while (i < 40)
		info[i++] = (unsigned char)0;
	info[0] = (unsigned char)40;
	i = game->win.width;
	info[4] = (unsigned char)(i % 256);
	info[5] = (unsigned char)(i / 256 % 256);
	info[6] = (unsigned char)(i / 256 / 256 % 256);
	info[7] = (unsigned char)(i / 256 / 256 / 256);
	i = game->win.height;
	info[8] = (unsigned char)(i % 256);
	info[9] = (unsigned char)(i / 256 % 256);
	info[10] = (unsigned char)(i / 256 / 256 % 256);
	info[11] = (unsigned char)(i / 256 / 256 / 256);
	info[12] = (unsigned char)1;
	info[14] = (unsigned char)32;
	write(fd, info, 40);
}

static void			screenshot_header(t_all *game, int fd)
{
	int				i;
	unsigned char	header[14];

	i = 0;
	while (i < 14)
		header[i++] = (unsigned int)0;
	header[0] = (unsigned char)0x42;
	header[1] = (unsigned char)0x4d;
	i = game->win.width * game->win.height * 4 + 54;
	header[2] = (unsigned char)(i % 256);
	header[3] = (unsigned char)(i / 256 % 256);
	header[4] = (unsigned char)(i / 256 / 256 % 256);
	header[5] = (unsigned char)(i / 256 / 256 / 256);
	header[10] = (unsigned char)54;
	write(fd, header, 14);
	screenshot_info(game, fd);
	screenshot_data(game->win.image, game->win.width, game->win.height, fd);
}

int					screenshot(t_all *game)
{
	int				fd;

	if ((fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, \
	S_IRWXU)) == -1)
	{
		printf("%s", "File creation failed.\n");
		return (0);
	}
	screenshot_header(game, fd);
	if (close(fd) == -1)
	{
		printf("%s", "Failed file closure.\n");
		return (0);
	}
	return (1);
}
