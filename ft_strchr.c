/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:53:29 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/23 17:28:47 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*s2;
	char		c2;

	c2 = (char)c;
	s2 = s;
	if (*s2 == '\0' && c == '\0')
		return ((char *)s2);
	while (*s2)
	{
		if (*s2++ == c2)
			return ((char *)--s2);
	}
	if (*s2 == '\0' && c == '\0')
		return ((char *)s2);
	return (NULL);
}
