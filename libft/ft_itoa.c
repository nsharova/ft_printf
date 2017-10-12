/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:13:53 by nsharova          #+#    #+#             */
/*   Updated: 2016/12/12 22:34:41 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digitlen(int n)
{
	size_t counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char			*ft_itoa(int n)
{
	char			*dest;
	size_t			len;
	unsigned int	d;
	int				flag;

	d = (n < 0) ? -n : n;
	flag = 0;
	if (n < 0)
		flag = 1;
	if (!(dest = (char*)malloc(sizeof(*dest) * (ft_digitlen(d) + 1 + flag))))
		return (NULL);
	if (flag == 1)
		dest[0] = '-';
	if (d == 0)
		dest[0] = '0';
	len = (n >= 0) ? ft_digitlen(d) : ft_digitlen(d) + 1;
	dest[len--] = '\0';
	while
		(d != 0)
	{
		dest[len] = '0' + (d % 10);
		d = d / 10;
		len--;
	}
	return (dest);
}
