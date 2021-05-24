/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselyse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 21:16:03 by gselyse           #+#    #+#             */
/*   Updated: 2020/05/12 21:16:03 by gselyse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list		*data;

	if ((data = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (!content)
		data->content = NULL;
	else
		data->content = (void*)content;
	data->next = NULL;
	return (data);
}
