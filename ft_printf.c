/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 11:14:20 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/28 11:15:34 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list		argptr;
	t_parsered	*inf;
	int			ret_value;

	ret_value = 0;
	va_start(argptr, s);
	while (*s)
		if (*s == '%')
		{
			if (!(inf = ft_parser((char *)++s)))
				break ;
			s += inf->length;
			if (inf->type == '\0')
				return (-1);
			processor_distributor(&argptr, inf);
			ret_value += inf->ret_value;
			free(inf);
		}
		else
		{
			write(1, s++, 1);
			ret_value++;
		}
	va_end(argptr);
	return (ret_value);
}
