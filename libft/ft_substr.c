/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 11:33:25 by gselyse           #+#    #+#             */
/*   Updated: 2020/05/05 11:33:25 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	lenstr;

	if (s == NULL)
		return (NULL);
	i = 0;
	lenstr = ft_strlen(s);
	if (lenstr < start)
		return (ft_strdup(""));
	if (len > lenstr)
		len = lenstr - start;
	dst = (char*)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	while (i < start)
	{
		s++;
		i++;
	}
	ft_strlcpy(dst, s, len + 1);
	return (dst);
}
