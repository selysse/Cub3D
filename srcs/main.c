/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:50:17 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/25 18:38:42 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		load_file(t_all *game, char *file_name)
{
	int			fd;
	char		*line;
	int			ret;
	t_list		*list;
	int			nb_oct;

	ret = TRUE;
	list = NULL;
	nb_oct = 1;
	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		printf("%s", "Couldn't open file.\n");
		return (EXIT_FAILURE);
	}
	while (nb_oct > 0)
	{
		nb_oct = get_next_line(fd, &line);
		ret = parse_line(line, game, &list);
		free(line);
	}
	close(fd);
	if (validation(game, list, ret))
		return (1);
	return (0);
}

static void		screen(t_all *game)
{
	display(game);
	screenshot(game);
	game->win.image.img = NULL;
	game->win.image.addr = NULL;
	exit_game(game);
}

static void		run_game(t_all *game, char *file_name)
{
	init_all(game);
	if (load_file(game, file_name))
	{
		game->win.image.img = mlx_new_image(game->win.mlx_ptr,\
		game->win.width, game->win.height);
		game->win.image.addr = mlx_get_data_addr(game->win.image.img,
		&game->win.image.bits_per_pixel, &game->win.image.line_length,\
		&game->win.image.endian);
		game->win.image.width = game->win.width;
		game->win.image.height = game->win.height;
		if (g_flag == 1)
			screen(game);
		else
		{
			game->win.win_ptr = mlx_new_window(game->win.mlx_ptr,
			game->win.width, game->win.height, "Cub3D");
			mlx_hook(game->win.win_ptr, 9, 1L << 21, &display, game);
			mlx_hook(game->win.win_ptr, 33, 1L << 17, &exit_game, game);
			mlx_hook(game->win.win_ptr, 2, 1L << 0, &deal_key, game);
			mlx_hook(game->win.win_ptr, 3, 1L << 1, &release_key, game);
			display(game);
			mlx_loop(game->win.mlx_ptr);
		}
	}
	exit_game(game);
}

int				exit_game(t_all *game)
{
	free_full(game);
	exit(0);
	return (1);
}

int				main(int argc, char **argv)
{
	t_all	game;

	if (argc == 3 || argc == 2)
	{
		if (argc == 3 && check_file(argv[1]) && ft_strequ(argv[2], "--save"))
		{
			g_flag = 1;
			run_game(&game, argv[1]);
		}
		else if (argc == 2)
		{
			g_flag = 0;
			if (check_file(argv[1]))
				run_game(&game, argv[1]);
			else
				printf("%s", "Not the good format of map's file .cub\n");
		}
		else
			printf("%s", "Invalid arguments.\n");
	}
	else
		printf("%s", "Invalid arguments.\n");
	return (0);
}
