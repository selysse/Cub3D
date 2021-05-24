/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:40:19 by gselyse           #+#    #+#             */
/*   Updated: 2020/04/30 14:40:19 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ppr;
	unsigned char	*cpr;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	cpr = (unsigned char*)dest;
	ppr = (unsigned char*)src;
	while (n > i)
	{
		cpr[i] = ppr[i];
		i++;
	}
	return (dest);
}
