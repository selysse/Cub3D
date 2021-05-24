/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 19:02:11 by gselyse           #+#    #+#             */
/*   Updated: 2020/05/11 19:02:11 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_longint(int a)
{
	int		i;
	long	nb;

	i = 1;
	nb = a;
	while (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	int			i;
	long		nn;

	len = ft_longint(n);
	i = 0;
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	nn = n;
	if (nn < 0)
		nn = -nn;
	str[len - i++] = '\0';
	while (nn > 9)
	{
		str[len - i++] = (nn % 10) + 48;
		nn = nn / 10;
	}
	str[len - i++] = (nn % 10) + 48;
	return (str);
}
