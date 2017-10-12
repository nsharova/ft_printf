/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 20:24:53 by nsharova          #+#    #+#             */
/*   Updated: 2016/12/11 22:28:37 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	n;
	char			*str;
	char			*dest;

	if (!s || !f)
		return (NULL);
	n = 0;
	str = ft_strnew(ft_strlen(s));
	if (str == NULL)
		return (NULL);
	dest = str;
	while (*s != '\0')
	{
		*str++ = (*f)(n, *s);
		s++;
		n++;
	}
	return (dest);
}
