/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 21:15:09 by gselyse           #+#    #+#             */
/*   Updated: 2020/05/13 21:15:09 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*elem;
	t_list	*tmp;
	void	*new_con;

	if ((del == NULL && f == NULL) || lst == NULL)
		return (NULL);
	if (!(new_con = f(lst->content)))
		return (NULL);
	if (!(list = ft_lstnew(new_con)))
		return (NULL);
	tmp = list;
	lst = lst->next;
	while (lst)
	{
		if (!(elem = ft_lstnew(new_con)))
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		tmp->next = elem;
		tmp = elem;
		lst = lst->next;
	}
	return (list);
}
