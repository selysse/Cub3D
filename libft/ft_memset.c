/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:51:01 by gselyse           #+#    #+#             */
/*   Updated: 2020/04/29 22:51:01 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	char			*ccb;
	unsigned char	a;

	i = 0;
	a = (unsigned char)c;
	ccb = (char*)s;
	while (n > 0)
	{
		ccb[i] = a;
		i++;
		n--;
	}
	return (s);
}
