/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 02:25:46 by gselyse           #+#    #+#             */
/*   Updated: 2020/05/04 02:25:46 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ccp;
	unsigned char	*ssp;
	size_t			i;

	i = 0;
	ccp = (unsigned char)c;
	ssp = (unsigned char *)s;
	while (n > 0)
	{
		if (ssp[i] == ccp)
			return ((void*)&ssp[i]);
		i++;
		n--;
	}
	return (NULL);
}
