/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 21:54:35 by nsharova          #+#    #+#             */
/*   Updated: 2016/12/16 20:25:25 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str1;
	char	*str2;
	size_t	counter;

	counter = 0;
	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0' && len != 0)
	{
		str1 = (char*)big;
		str2 = (char*)little;
		if (*str2 == *str1)
			counter = 0;
		while (*str2 == *str1 && *str2 != '\0' &&
		*str1 != '\0' && counter++ < len)
		{
			str2++;
			str1++;
		}
		if (*str2 == '\0')
			return ((char*)big);
		big++;
		len--;
	}
	return (0);
}
