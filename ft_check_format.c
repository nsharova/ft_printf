/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 22:46:31 by nsharova          #+#    #+#             */
/*   Updated: 2017/10/13 16:00:20 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_prefix(t_print *list)
{
	if (DECIMAL(list->conversion))
	{
		if (list->sign == 1)
			*(list->prefix) = '-';
		else if (PLUS(list->flag))
			*(list->prefix) = '+';
		else if (SPACE(list->flag))
			*(list->prefix) = ' ';
	}
	else if (UOCT(list->conversion) && SHARP(list->flag) && *list->buf != '0')
		*(list->prefix) = '0';
	else if (UHEX(list->conversion) && SHARP(list->flag) && *list->buf != '0')
		list->prefix = (list->conversion == 'x') ?
			ft_strjoin(list->prefix, "0x") : ft_strjoin(list->prefix, "0X");
	else if (list->conversion == 'p')
		list->prefix = ft_strjoin(list->prefix, "0x");
	return ;
}

void		ft_check_size(t_print *list)
{
	if (list->z == 1)
		list->size = 'z';
	else if (list->j == 1)
		list->size = 'j';
	else if (list->l > 0)
	{
		if (((list->l) % 2) == 0)
			list->size = 'L';
		else
			list->size = 'l';
	}
	else if ((list->h) > 0)
	{
		if (((list->h) % 2) == 0)
			list->size = 'H';
		else
			list->size = 'h';
	}
}

t_print		*ft_new_list(t_print *list)
{
	if (!(list = (t_print*)ft_memalloc(sizeof(t_print))))
		return (NULL);
	list->prefix = ft_strnew(2);
	return (list);
}
