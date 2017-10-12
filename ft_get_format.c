/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 19:31:55 by nsharova          #+#    #+#             */
/*   Updated: 2017/10/12 23:04:08 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_get_format(t_print *list, const char *fm)
{
	while (*fm && ft_strchr("-+ #0.123456789lhzj", *fm))
	{
		while (FLAG(*fm))
			ft_get_flag(list, *(fm++));
		if ((*fm) >= '1' && (*fm) <= '9')
		{
			list->width = 0;
			while (ft_isdigit(*fm))
				list->width = (list->width * 10) + (*fm++) - '0';
		}
		if (*fm == '.')
		{
			list->dot = 1;
			list->precision = 0;
			while (ft_isdigit((*(++fm))))
				list->precision = (list->precision * 10) + (*fm) - '0';
		}
		while (*fm && ft_strchr("lhzj", *fm))
			ft_get_size(list, *(fm++));
	}
	ft_check_size(list);
	ft_check_converse(list, &fm);
	return (fm);
}

void		ft_check_converse(t_print *list, const char **fm)
{
	if (**fm && CONVERSE(**fm))
		list->conversion = **fm;
	else if (*fm && !(CONVERSE(**fm)))
	{
		list->buf = ft_memalloc(2);
		*(list->buf) = **fm;
	}
}

void		ft_get_flag(t_print *list, char fm)
{
	if (fm == '#')
		list->flag |= 0x01;
	else if (fm == '0')
		list->flag |= 0x01 << 1;
	else if (fm == '-')
		list->flag |= 0x01 << 2;
	else if (fm == '+')
		list->flag |= 0x01 << 3;
	else if (fm == ' ')
		list->flag |= 0x01 << 4;
}

void		ft_get_size(t_print *list, char fm)
{
	if (fm == 'l')
		list->l++;
	else if (fm == 'h')
		list->h++;
	else if (fm == 'z')
		list->z = 1;
	else if (fm == 'j')
		list->j = 1;
}
