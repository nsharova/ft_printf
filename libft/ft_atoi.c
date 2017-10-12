/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:36:18 by nsharova          #+#    #+#             */
/*   Updated: 2016/12/12 21:06:29 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int value;
	int sign;

	value = 0;
	sign = 1;
	while ((*str == '\0') || (*str == ' ') || (*str == '\v') || (*str == '\f')
	|| (*str == '\r') || (*str == '\t') || (*str == '\n'))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		value *= 10;
		value += *str - '0';
		str++;
	}
	return (value * sign);
}
