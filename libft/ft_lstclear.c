/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 19:00:46 by gselyse           #+#    #+#             */
/*   Updated: 2020/05/13 19:00:46 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*cmp;

	tmp = *lst;
	if (lst && del)
	{
		while (tmp != NULL)
		{
			cmp = tmp;
			tmp = tmp->next;
			ft_lstdelone(cmp, del);
		}
		*lst = NULL;
	}
}
