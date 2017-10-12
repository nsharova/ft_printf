/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 20:47:38 by nsharova          #+#    #+#             */
/*   Updated: 2016/12/12 22:33:22 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *next;

	list = (*alst)->next;
	while (list)
	{
		next = list->next;
		ft_lstdelone(&list, del);
		list = next;
	}
	ft_lstdelone(alst, del);
}
