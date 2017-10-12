/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:34:49 by nsharova          #+#    #+#             */
/*   Updated: 2016/12/16 20:51:29 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (dst <= src)
	{
		while (n-- != 0)
			*d++ = *s++;
	}
	if (dst > src)
	{
		while (n-- != 0)
			*(d + n) = *(s + n);
	}
	return (dst);
}
