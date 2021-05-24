/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 14:38:49 by gselyse           #+#    #+#             */
/*   Updated: 2020/05/04 14:38:49 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t n)
{
	size_t		i;
	char		*res;

	if (*src == '\0')
		return ((char*)dst);
	while (*dst != '\0' && n > 0)
	{
		i = 0;
		res = (char*)dst;
		while ((dst[i] == src[i]) && (src[i] != '\0') && ((i - n) > 0))
			i++;
		if (src[i] == '\0')
			return (res);
		dst++;
		n--;
	}
	return (NULL);
}
