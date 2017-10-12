/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:59:59 by nsharova          #+#    #+#             */
/*   Updated: 2016/12/11 21:27:26 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *str;
	char *str1;

	if (!s || !f)
		return (0);
	str = ft_strnew(ft_strlen(s));
	if (str == NULL)
		return (NULL);
	str1 = str;
	while (*s != '\0')
		*str++ = (*f)(*s++);
	return (str1);
}
