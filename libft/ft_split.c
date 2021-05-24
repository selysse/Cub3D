/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 15:14:11 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/08 12:44:05 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_memoryfree(char **s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static	const char	*ft_skip(const char *s, char c)
{
	while (*s == c && *s != '\0')
		s++;
	return (s);
}

static	int			ft_count_words(char const *str, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != c && str[i] != '\0')
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

static	int			ft_get_str(const char *s, char c)
{
	int				res;

	res = 0;
	while (*s && *s != c)
	{
		s++;
		res++;
	}
	return (res);
}

char				**ft_split(char const *s, char c)
{
	unsigned int	strnew_len;
	unsigned int	wrds;
	unsigned int	i;
	char			**str;

	if (s == NULL)
		return (NULL);
	wrds = ft_count_words(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (wrds + 1))))
		return (NULL);
	i = 0;
	while (i < wrds)
	{
		s = ft_skip(s, c);
		strnew_len = ft_get_str(s, c);
		if (!(str[i] = (char *)malloc(sizeof(char) * (strnew_len + 1))))
			return (ft_memoryfree(str));
		ft_strlcpy(str[i], s, strnew_len + 1);
		s += strnew_len;
		i++;
	}
	str[i] = NULL;
	return (str);
}
