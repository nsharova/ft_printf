/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 22:47:54 by nsharova          #+#    #+#             */
/*   Updated: 2016/12/12 15:21:41 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *str1;
	const char *str2;

	if (*little == '\0')
		return ((char*)big);
	while (*big)
	{
		str1 = big;
		str2 = little;
		while (*str2 == *str1 && *str1 != '\0' && *str2 != '\0')
		{
			str2++;
			str1++;
		}
		if (*str2 == '\0')
		{
			return ((char*)big);
		}
		big++;
	}
	return (NULL);
}
