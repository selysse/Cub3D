/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:52:34 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/25 17:56:37 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		record_list_map(t_all *game, t_list **list, char *line)
{
	game->in_map = 1;
	if (line[0] != '\0')
	{
		ft_lstadd_back(list, ft_lstnew(ft_strdup(line)));
		return (1);
	}
	printf("%s", "Empty line in map.\n");
	return (0);
}

static int		pars_err(char *str)
{
	printf("%s", str);
	exit(-1);
}

int				parse_line(char *line, t_all *game, t_list **list)
{
	char		**tab_line;
	int			ret;

	ret = 1;
	tab_line = ft_split(line, ' ');
	if (*tab_line && *tab_line[0] == 'R' && !game->in_map)
		ret = parsing_resolution(game, tab_line);
	else if (*tab_line && is_texture(tab_line) && !game->in_map)
		ret = parsing_texture(game, tab_line);
	else if (*tab_line && (ft_strequ(*tab_line, "F") ||
		ft_strequ(*tab_line, "C")) && !game->in_map)
		ret = color(game, tab_line);
	else if (*tab_line && *tab_line[0] == '1')
		ret = record_list_map(game, list, line);
	else if (!*tab_line && game->in_map)
		pars_err("Empty line in map.\n");
	else if (*tab_line && !game->in_map)
		pars_err("Bad arguments in file .cub.\n");
	else if (game->in_map)
		pars_err("arguments in end of map forbbiden.\n");
	if (*tab_line)
		free_tab(tab_line);
	free(tab_line);
	return (ret);
}
