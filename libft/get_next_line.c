/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 18:31:35 by gselyse           #+#    #+#             */
/*   Updated: 2020/10/16 12:30:49 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lstcleart(t_lists **head)
{
	t_lists		*tmp;

	if (head)
		if (*head)
			while (*head)
			{
				tmp = (*head)->next;
				if ((*head)->rest)
					free((*head)->rest);
				free(*head);
				*head = tmp;
			}
	return (1);
}

static	void	ft_clear(t_lists **head, t_lists **tmp)
{
	t_lists		*tpp;

	if ((*tmp)->rest)
	{
		free((*tmp)->rest);
		(*tmp)->rest = NULL;
	}
	if (*head == *tmp)
		*head = (*head)->next;
	else
	{
		tpp = *head;
		while (tpp->next != *tmp)
			tpp = tpp->next;
		tpp->next = (*tmp)->next;
	}
	free(*tmp);
}

static int		check_rem(t_lists *tmp, char **line)
{
	char		*p_n;
	char		*rem;

	p_n = NULL;
	if (tmp->rest)
		if ((p_n = ft_strchr(tmp->rest, '\n')))
		{
			*p_n = '\0';
			*line = ft_strdup_gnl(tmp->rest);
			rem = tmp->rest;
			tmp->rest = ft_strdup_gnl(++p_n);
			free(rem);
			if (!(*line) || !(tmp->rest))
				return (-1);
		}
		else
		{
			if (!(*line = ft_strdup_gnl(tmp->rest)))
				return (-1);
			free(tmp->rest);
			tmp->rest = NULL;
		}
	else if (!(*line = ft_strdup_gnl("")))
		return (-1);
	return (0);
}

static int		get_line(t_lists *tmp, char **line, char *buf)
{
	int				byte_was_read;
	char			*p_n;

	byte_was_read = 0;
	if ((check_rem(tmp, line)) == -1)
		return (-1);
	while (!(tmp->rest) && (byte_was_read = read(tmp->fd, buf, BUFFER_SIZE)))
	{
		if (byte_was_read < 0)
			return (-1);
		buf[byte_was_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')) != NULL)
		{
			*p_n = '\0';
			if (!(tmp->rest = ft_strdup_gnl(++p_n)))
				return (-1);
		}
		if (!(*line = ft_strjoin_gnl(line, buf)))
			return (-1);
	}
	free(buf);
	return ((byte_was_read || tmp->rest) ? 1 : 0);
}

int				get_next_line(int fd, char **line)
{
	static t_lists	*head;
	t_lists			*tmp;
	char			*buf;
	int				res;

	if (fd < 0 || !line || (BUFFER_SIZE < 1))
		return (-1);
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (head == NULL)
		if (!(head = ft_add(fd)))
			return (-1);
	tmp = head;
	while (tmp && tmp->fd != fd)
	{
		if (tmp->next == NULL)
			if (!(tmp->next = ft_add(fd)) && ft_lstcleart(&head))
				return (-1);
		tmp = tmp->next;
	}
	if ((res = get_line(tmp, line, buf)) == 0)
		ft_clear(&head, &tmp);
	if (res == -1)
		ft_lstcleart(&head);
	return (res);
}
