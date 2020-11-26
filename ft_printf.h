/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:47:37 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/26 18:12:53 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct 				s_parsered
{
	int				flag_minus;
	int				flag_nul;
	int				width;
	int				precision_flag;
	int				precision;
	char			type;
	int				length;
}							t_parsered;

t_parsered *ft_parser(char *unparsed);
size_t	ft_strlen(const char *s);
int	ft_printf(const char *s, ...);
void ft_parsered_flags(t_parsered *inf, char *unparsed);
int ft_parsered_width(t_parsered *inf, char *unparsed);
int ft_parsered_precision(t_parsered *inf, char *unparsed);
t_parsered *ft_parser(char *unparsed);
char	*ft_strchr(const char *s, int c);
int	ft_isdigit(int c);
void processor_distributor(va_list *argptr, t_parsered *inf);
void process_16base(va_list *argptr, t_parsered *inf);
void process_unsigned_number(va_list *argptr, t_parsered *inf);
void process_number(va_list *argptr, t_parsered *inf);
void process_ptr(va_list *argptr, t_parsered *inf);
void process_str(va_list *argptr, t_parsered *inf);
void process_char(va_list *argptr, t_parsered *inf);
void	ft_putchar_fd(char c);
int	ft_atoi(const char *str);
char			*ft_itoa(int n);
int				counter(int n);
int				u_counter(int n);
char			*ft_u_itoa(int n);
void	ft_putnbr_fd(int n);
void	ft_put_u_nbr_fd(int n);
void init(t_parsered *inf);
void process_alignment(int len, t_parsered *inf, char type);
void counter_helper_costyl(int *count_nul, int *count_spaces, int numb, t_parsered *inf);
void counter_nul_spaces(int *count_nul, int *count_spaces, int len, t_parsered *inf);
void process_16base_big(va_list *argptr, t_parsered *inf);
void process_16base_small(va_list *argptr, t_parsered *inf);
void	ft_putnbr_fd_16x(unsigned int n, int x);
int				counter_16x(unsigned int n);

#endif
