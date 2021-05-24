/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:57:54 by gselyse           #+#    #+#             */
/*   Updated: 2020/05/04 18:57:54 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_memb, size_t size)
{
	void *s;

	s = malloc(n_memb * size);
	if (s == NULL)
		return (NULL);
	else if (s != NULL)
		ft_memset(s, 0, n_memb * size);
	return (s);
}
