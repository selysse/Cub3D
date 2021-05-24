/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:18:26 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/24 19:00:24 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	check_line(char line, int *p)
{
	if (!line)
		return (0);
	if (!ft_isdigit(line))
	{
		*p = -3;
		return (0);
	}
	return (1);
}

int	check_separator(char *line, int *p)
{
	if (!*line)
		return (0);
	if (*line != ',' || !ft_isdigit(line[1]))
	{
		*p = -3;
		return (0);
	}
	return (1);
}

int	is_number(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
