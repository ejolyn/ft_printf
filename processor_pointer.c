/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:28:42 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/28 11:19:30 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_ptr(va_list *argptr, t_parsered *inf)
{
	size_t	numb;
	int		len;
	int		count_spaces;

	numb = va_arg(*argptr, size_t);
	len = (!(numb == 0 && inf->precision_flag == 1
				&& inf->precision == 0)) ? counter_16x(numb) : 0;
	count_spaces = inf->width - len - 2;
	if (count_spaces > 0)
		inf->ret_value += count_spaces;
	if (inf->flag_minus == 0)
		while (count_spaces-- > 0)
			write(1, " ", 1);
	inf->ret_value += len + 2;
	write(1, "0x", 2);
	if (!(numb == 0 && inf->precision_flag == 1 && inf->precision == 0))
		ft_putnbr_fd_16x(numb, 'a');
	if (inf->flag_minus == 1)
		while (count_spaces-- > 0)
			write(1, " ", 1);
}

void	process_procent(t_parsered *inf)
{
	int		count_spaces;
	char	type;

	inf->ret_value = 1;
	if (inf->flag_nul == 1)
		type = '0';
	else
		type = ' ';
	count_spaces = inf->width - 1;
	inf->length = inf->length + 1;
	if (inf->flag_minus == 0)
		process_alignment(1, inf, type);
	write(1, "%", 1);
	if (inf->flag_minus == 1)
		process_alignment(1, inf, type);
}
