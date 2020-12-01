/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:31:57 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/28 11:41:25 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_char(va_list *argptr, t_parsered *inf)
{
	unsigned char c;

	inf->ret_value = 1;
	if (inf->flag_minus == 0)
		process_alignment(1, inf, ' ');
	c = (unsigned char)va_arg(*argptr, int);
	write(1, &c, 1);
	if (inf->flag_minus == 1)
		process_alignment(1, inf, ' ');
}

void	process_str(va_list *argptr, t_parsered *inf)
{
	char	*str;
	size_t	len;

	str = va_arg(*argptr, char*);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (inf->precision < (int)len && inf->precision_flag == 1)
		len = inf->precision;
	inf->ret_value = len;
	if (inf->flag_minus == 0)
		process_alignment(len, inf, ' ');
	write(1, str, len);
	if (inf->flag_minus == 1)
		process_alignment(len, inf, ' ');
}

void	process_alignment(int len, t_parsered *inf, char type)
{
	if (inf->width > len)
	{
		inf->ret_value = inf->width;
		while (len < inf->width--)
			write(1, &type, 1);
	}
}

void	processor_negative_width(va_list *argptr, t_parsered *inf)
{
	if (inf->width == -1)
		inf->width = va_arg(*argptr, int);
	if (inf->precision == -1)
		inf->precision = va_arg(*argptr, int);
	if (inf->width < 0)
	{
		inf->flag_minus = 1;
		inf->width *= -1;
	}
	if (inf->precision < 0)
	{
		inf->precision = 0;
		inf->precision_flag = 0;
	}
	if (inf->flag_nul == 1 && inf->precision_flag == 1)
		inf->flag_nul = 0;
	if (inf->flag_nul && inf->flag_minus)
		inf->flag_nul = 0;
}

void	processor_distributor(va_list *argptr, t_parsered *inf)
{
	processor_negative_width(argptr, inf);
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
	else if (inf->type == 'x')
		process_16base_small(argptr, inf);
	else if (inf->type == 'X')
		process_16base_big(argptr, inf);
	else if (inf->type == '%')
		process_procent(inf);
}
