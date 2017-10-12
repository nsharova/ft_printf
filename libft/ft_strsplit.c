/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 20:29:10 by nsharova          #+#    #+#             */
/*   Updated: 2016/12/10 17:11:46 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	len;
	char	**dest;
	char	*str;
	size_t	i;

	i = 0;
	dest = (char**)malloc((ft_count_words(s, c) + 1) * sizeof(char*));
	if (!dest || !s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			str = (char*)s;
			len = 0;
			while (*s && *s++ != c)
				len++;
			if (len != 0)
				dest[i++] = ft_strsub(str, 0, len);
		}
	}
	dest[i] = NULL;
	return (dest);
}
