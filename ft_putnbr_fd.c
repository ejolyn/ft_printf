/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:39:32 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/26 17:09:00 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c)
{
	int i;

	i = write(1, &c, 1);
}

void	ft_put_u_nbr_fd(int n)
{
	unsigned int n2;

	n2 = n;
	if (n2 > 9)
	{
		ft_putnbr_fd(n2 / 10);
		ft_putnbr_fd(n2 % 10);
	}
	else
		ft_putchar_fd(n2 + '0');
}

void	ft_putnbr_fd(int n)
{
	if (n < 0 && n != -2147483648)
	{
		ft_putnbr_fd(-n);
	}
	else if (n == -2147483648)
	{
		write(1, "2", 2);
		ft_putnbr_fd(147483648);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10);
		ft_putnbr_fd(n % 10);
	}
	else
		ft_putchar_fd(n + '0');
}

int				counter(int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int				u_counter(int n)
{
	int len;
	unsigned int n2;

	n2 = n;
	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}