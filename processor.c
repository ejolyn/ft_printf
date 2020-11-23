/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:31:57 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/23 17:34:16 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void process_char(va_list *argptr, t_parsered *inf)
{
	unsigned char c;

	inf->width = 0;
	c = (unsigned char)va_arg(*argptr, int);
	write (1, &c, 1);
}

void process_str(va_list *argptr, t_parsered *inf)
{
	char	*str;
	size_t		len;

	inf->width = 0;
	str = va_arg(*argptr, char*);
	len = ft_strlen(str);
	write (1, str, len);
}

void process_ptr(va_list *argptr, t_parsered *inf)
{
	void	*ptr;
	int		len;

	inf->width = 0;
	len = 0;
	ptr = va_arg(*argptr, void*);
	write (1, ptr, len);
}

void process_number(va_list *argptr, t_parsered *inf)
{
	int		numb;
	int		len;

	inf->width = 0;
	len = 0;
	numb = va_arg(*argptr, int);
	write (1, ft_itoa(numb), len);
}
void process_unsigned_number(va_list *argptr, t_parsered *inf)
{
	unsigned int		numb;
	size_t		len;

	inf->width = 0;
	len = 0;
	numb = va_arg(*argptr, unsigned int);
	if (numb < 0)
		numb *= -1;
	write (1, ft_itoa(numb), len);
}
void process_16base(va_list *argptr, t_parsered *inf)
{
	inf->width = 0;
	argptr = 0;
	return ;
}
void processor_distributor(va_list *argptr, t_parsered *inf)
{
	if (inf->type == 'c')
		process_char(argptr, inf);
	else if (inf->type == 's')
		process_str(argptr, inf);
	else if (inf->type == 'p')
		process_ptr(argptr, inf);
	else if (inf->type == 'd' || inf->type == 'i')
		process_number(argptr, inf);
	else if (inf->type == 'u')
		process_unsigned_number(argptr, inf);
	else if (inf->type == 'x' || inf->type == 'X')
		process_16base(argptr, inf);
}