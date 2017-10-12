/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:47:21 by nsharova          #+#    #+#             */
/*   Updated: 2016/12/13 22:18:00 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dest;
	int		i;
	int		n;

	i = 0;
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
	{
		s++;
		if (*s == '\0')
			return (ft_strnew(1));
	}
	while (s[i] != '\0')
		i++;
	i = i - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	n = ++i;
	dest = ft_strnew(i);
	if (dest == NULL)
		return (NULL);
	while (i-- > 0)
		*dest++ = *s++;
	return (dest - n);
}
