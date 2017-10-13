/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 14:20:37 by nsharova          #+#    #+#             */
/*   Updated: 2017/10/13 15:58:09 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_num_wchar_zero(t_print *list, size_t *ret)
{
	if (!ZERO(list->flag))
	{
		while ((list->width)--)
		{
			ft_putchar(' ');
			(*ret)++;
		}
	}
	else
		while ((list->width)--)
		{
			ft_putchar('0');
			(*ret)++;
		}
}

void	ft_print_null_char(t_print *list, size_t *ret)
{
	(*ret) += list->width;
	list->width--;
	while (list->width--)
		ft_putchar('0');
	ft_putchar('\0');
}
