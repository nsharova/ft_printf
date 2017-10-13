/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 20:52:17 by nsharova          #+#    #+#             */
/*   Updated: 2017/10/12 23:03:55 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_get_arg(t_print *list, va_list *args)
{
	if (DECIMAL(list->conversion))
		ft_get_digit(list, args);
	else if (UNSIGN(list->conversion))
		ft_get_unsigned(list, args);
	else if (SYMB(list->conversion))
		ft_get_char(list, args);
	else if (STRING(list->conversion))
		ft_get_string(list, args);
}

void		ft_get_char(t_print *list, va_list *args)
{
	char	c;

	if (SYMB(list->conversion))
	{
		if (!(c = (char)va_arg(*args, int)))
			list->buf = ft_strdup("\0");
		else
		{
			list->buf = ft_strnew(1);
			(*list->buf) = c;
		}
	}
}

void		ft_get_string(t_print *list, va_list *args)
{
	char	*s;
	wchar_t	*wchar;

	if (list->conversion == 'S' || (list->conversion == 's' &&
									(list->l % 2)))
	{
		if ((wchar = va_arg(*args, wchar_t*)) == NULL)
			list->buf = ft_strdup("(null)");
		else
			list->buf = ft_push_wchar(wchar, list);
	}
	else if (list->conversion == 's')
	{
		if ((s = va_arg(*args, char*)) == NULL)
			list->buf = ft_push_char(list, "(null)");
		else
			list->buf = ft_push_char(list, s);
	}
}

void		ft_get_unsigned(t_print *list, va_list *args)
{
	ssize_t	unsign;

	if (USHORT(list->conversion) && (list->size == 'H'))
		unsign = (unsigned char)va_arg(*args, unsigned int);
	else if (USHORT(list->conversion) && (list->size == 'h'))
		unsign = (unsigned short)va_arg(*args, unsigned int);
	else if ((USHORT(list->conversion) && (list->size == 'l'))
		|| ULONG(list->conversion))
		unsign = va_arg(*args, unsigned long);
	else if (USHORT(list->conversion) && (list->size == 'L'))
		unsign = va_arg(*args, unsigned long long);
	else if (USHORT(list->conversion) && (list->size == 'j'))
		unsign = va_arg(*args, uintmax_t);
	else if ((USHORT(list->conversion) && (list->size == 'z'))
		|| (list->conversion == 'p'))
		unsign = va_arg(*args, size_t);
	else
		unsign = va_arg(*args, unsigned int);
	if (UOCT(list->conversion))
		list->buf = ft_itoa_base(unsign, 8);
	else if (UDECIMAL(list->conversion))
		list->buf = ft_itoa_base(unsign, 10);
	else
		list->buf = (list->conversion == 'X') ?
			ft_itoa_base(unsign, 16) : ft_low(ft_itoa_base(unsign, 16));
}

void		ft_get_digit(t_print *list, va_list *args)
{
	ssize_t	digit;

	if (LDECIMAL(list->conversion) && (list->size == 'H'))
		digit = (char)va_arg(*args, int);
	else if (LDECIMAL(list->conversion) && (list->size == 'h'))
		digit = (short)va_arg(*args, int);
	else if ((LDECIMAL(list->conversion) && list->l % 2)
		|| list->conversion == 'D')
		digit = va_arg(*args, long);
	else if (LDECIMAL(list->conversion) && (list->size == 'L'))
		digit = va_arg(*args, long long);
	else if (LDECIMAL(list->conversion) && (list->size == 'j'))
		digit = va_arg(*args, intmax_t);
	else if (LDECIMAL(list->conversion) && (list->size == 'z'))
		digit = va_arg(*args, ssize_t);
	else
		digit = va_arg(*args, int);
	(digit < 0) ? list->sign = 1 : 0;
	digit = (digit < 0) ? (-digit) : digit;
	list->buf = ft_itoa_base(digit, 10);
}
