/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_16x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:21:42 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/28 11:43:25 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		counter_16x(size_t n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	ft_putnbr_fd_16x(size_t n2, int x)
{
	if (n2 > 15)
	{
		ft_putnbr_fd_16x(n2 / 16, x);
		ft_putnbr_fd_16x(n2 % 16, x);
	}
	else if (n2 % 16 > 9)
		ft_putchar_fd((n2 % 16) - 10 + x);
	else
		ft_putchar_fd(n2 % 16 + '0');
}

void	process_16base_small(va_list *argptr, t_parsered *inf)
{
	unsigned int	numb;
	int				len;
	int				count_spaces;

	numb = va_arg(*argptr, int);
	len = counter_16x(numb);
	len = (numb < 0) ? len + 1 : len;
	count_spaces = 0;
	counter_nul_spaces(&count_spaces, len, inf);
	counter_helper(&count_spaces, numb, inf, len);
	if (inf->flag_minus == 0)
		while (count_spaces--)
			write(1, " ", 1);
	if (numb < 0)
		write(1, "-", 1);
	if (!(numb == 0 && inf->precision_flag == 1 && inf->precision == 0))
	{
		while (inf->count_nul--)
			write(1, "0", 1);
		ft_putnbr_fd_16x(numb, 'a');
	}
	if (inf->flag_minus == 1)
		while (count_spaces--)
			write(1, " ", 1);
}

void	process_16base_big(va_list *argptr, t_parsered *inf)
{
	unsigned int	numb;
	int				len;
	int				count_spaces;

	numb = va_arg(*argptr, int);
	len = counter_16x(numb);
	len = (numb < 0) ? len + 1 : len;
	count_spaces = 0;
	counter_nul_spaces(&count_spaces, len, inf);
	counter_helper(&count_spaces, numb, inf, len);
	if (inf->flag_minus == 0)
		while (count_spaces--)
			write(1, " ", 1);
	if (numb < 0)
		write(1, "-", 1);
	if (!(numb == 0 && inf->precision_flag == 1 && inf->precision == 0))
	{
		while (inf->count_nul--)
			write(1, "0", 1);
		ft_putnbr_fd_16x(numb, 'A');
	}
	if (inf->flag_minus == 1)
		while (count_spaces--)
			write(1, " ", 1);
}
