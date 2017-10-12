/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsharova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:28:34 by nsharova          #+#    #+#             */
/*   Updated: 2016/12/14 19:25:21 by nsharova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *dest;

	if (!s1 && !s2)
		return (NULL);
	if (s1 == NULL)
	{
		if (!(dest = ft_strnew(ft_strlen(s2))))
			return (NULL);
		return (ft_strcpy(dest, (char*)s2));
	}
	if (s2 == NULL)
	{
		if (!(dest = ft_strnew(ft_strlen(s1))))
			return (NULL);
		return (ft_strcpy(dest, (char*)s1));
	}
	else
	{
		if (!(dest = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		dest = ft_strcat(dest, (char*)s1);
		dest = ft_strcat(dest, (char*)s2);
		return (dest);
	}
}
