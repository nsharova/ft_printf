/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:57:26 by nsharova          #+#    #+#             */
/*   Updated: 2016/12/16 19:01:19 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n != 0)
	{
		if (*s1 == '\0' || *s1 != *s2 || *s2 == '\0')
			return (*(unsigned char*)s1 - *(unsigned char*)s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
