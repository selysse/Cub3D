/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:30:52 by gselyse           #+#    #+#             */
/*   Updated: 2020/05/07 14:30:52 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	while (n > 0)
	{
		d[i] = s[i];
		if (s[i] == (unsigned char)c)
		{
			i++;
			return ((void*)&d[i]);
		}
		i++;
		n--;
	}
	return (NULL);
}
