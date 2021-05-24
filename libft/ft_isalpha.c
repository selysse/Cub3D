/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <gselyse@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:13:53 by gselyse           #+#    #+#             */
/*   Updated: 2021/03/17 15:48:20 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_max(int n1, int n2)
{
	return ((n1 > n2) ? n1 : n2);
}

int	ft_min(int n1, int n2)
{
	return ((n1 < n2) ? n1 : n2);
}
