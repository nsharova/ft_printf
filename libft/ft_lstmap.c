/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 23:44:11 by nsharova          #+#    #+#             */
/*   Updated: 2016/12/12 23:11:49 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	list = NULL;
	if ((list = (*f)(lst)) == NULL)
		return (NULL);
	new = list;
	while (lst->next)
	{
		if ((new->next = (*f)(lst->next)) == NULL)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (list);
}
