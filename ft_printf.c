/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:22:06 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/23 17:35:49 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list argptr;
	t_parsered *inf;

	va_start(argptr, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1) != '%')
		{
			inf = ft_parser((char *)++s);
			s += inf->length;
			processor_distributor(&argptr, inf);
			continue ;
		}
		else if (*s == '%' && *(s + 1) == '%')
		{
			write (1, "%", 1);
			s++;
		}
		else
			write (1, s, 1);
		s++;
	}
	va_end(argptr);
	return (0);
}