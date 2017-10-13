/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 22:10:28 by nsharova          #+#    #+#             */
/*   Updated: 2017/10/13 21:25:33 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_arg(t_print *list, size_t *ret)
{
	(*(list->buf) == '0' && list->conversion == 'p' && list->dot &&
	!(list->precision)) ? (*list->buf = '\0') : 0;
	(NUM(list->conversion) || list->conversion == 'p') ?
		ft_check_prefix(list) : 0;
	(NUM(list->conversion) || list->conversion == 'p') ?
		0 : (list->precision = 0);
	if (UOCT(list->conversion))
		list->len_p = (list->precision >
		ft_strlen(list->buf) + ft_strlen(list->prefix)) ?
		(list->precision - ft_strlen(list->buf) -
		ft_strlen(list->prefix)) : 0;
	else
		list->len_p = (list->precision > ft_strlen(list->buf)) ?
		(list->precision - ft_strlen(list->buf)) : 0;
	list->len_w = (list->width > ft_strlen(list->buf)
	+ list->len_p + ft_strlen(list->prefix)) ?
		(list->width - ft_strlen(list->buf)
	- list->len_p - ft_strlen(list->prefix)) : 0;
	(*list->buf == '\0' && SYMB(list->conversion) && (list->width)) ?
	(list->len_w--) : 0;
	*ret = MINUS(list->flag) ? ft_print_left(list, *ret) :
		ft_print_right(list, *ret);
}

size_t	ft_print_left(t_print *list, size_t ret)
{
	ft_putstr(list->prefix);
	ret += ft_strlen(list->prefix);
	ret += list->len_p;
	while ((list->len_p)--)
		ft_putchar('0');
	if (*list->buf == '\0' && SYMB(list->conversion))
	{
		ret++;
		ft_putchar('\0');
	}
	else
	{
		ft_putstr(list->buf);
		ret += ft_strlen(list->buf);
	}
	ret += list->len_w;
	while ((list->len_w)--)
		ft_putchar(' ');
	return (ret);
}

void	ft_print_right_post(t_print *list, size_t *ret)
{
	ft_putstr(list->prefix);
	(*ret) += ft_strlen(list->prefix);
	(*ret) += list->len_w;
	while ((list->len_w)--)
		ft_putchar('0');
	if (*list->buf == '\0' && SYMB(list->conversion))
	{
		(*ret)++;
		ft_putchar('\0');
	}
	else
	{
		ft_putstr(list->buf);
		(*ret) += ft_strlen(list->buf);
	}
}

void	ft_print_right_pref(t_print *list, size_t *ret)
{
	(*ret) += list->len_w;
	while ((list->len_w)--)
		ft_putchar(' ');
	ft_putstr(list->prefix);
	(*ret) += ft_strlen(list->prefix);
	(*ret) += list->len_p;
	while ((list->len_p)--)
		ft_putchar('0');
	if (*list->buf == '\0' && SYMB(list->conversion))
	{
		(*ret)++;
		ft_putchar('\0');
	}
	else
	{
		ft_putstr(list->buf);
		(*ret) += ft_strlen(list->buf);
	}
}

size_t	ft_print_right(t_print *list, size_t ret)
{
	if ((!list->conversion || SYMB(list->conversion)) && ZERO(list->flag) &&
	list->width)
		ft_print_right_post(list, &ret);
	else if ((!ZERO(list->flag)) || ((ZERO(list->flag) && (list->precision))
	|| (ZERO(list->flag) && !(list->precision) && list->dot)))
		ft_print_right_pref(list, &ret);
	else
		ft_print_right_post(list, &ret);
	return (ret);
}
