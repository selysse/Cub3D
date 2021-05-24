/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:08:14 by gselyse           #+#    #+#             */
/*   Updated: 2020/05/01 16:08:14 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ccp;
	unsigned char	*ppc;

	i = 0;
	ccp = (unsigned char*)s1;
	ppc = (unsigned char*)s2;
	while (n > 0)
	{
		if (ccp[i] != ppc[i])
			return ((int)(ccp[i] - ppc[i]));
		i++;
		n--;
	}
	return (0);
}
