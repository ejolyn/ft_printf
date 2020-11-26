/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:36:53 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/26 16:38:27 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_parsered_flags(t_parsered *inf, char *unparsed)
{
	inf->flag_nul = 0;
	inf->flag_minus = 0;
	while (*unparsed == '-' || *unparsed == '0')
	{
		if (*unparsed == '0')
			inf->flag_nul = 1;
		else
			inf->flag_minus = 1;
		inf->length++;
		unparsed++;
	}
	if (inf->flag_nul && inf->flag_minus)
		inf->flag_nul = 0;
}

int ft_parsered_width(t_parsered *inf, char *unparsed)
{
	char 	width[100];
	int		i;

	i = 0;
	if (*unparsed == '*')
	{
		inf->width = -1;
		inf->length++;
		return (1);
	}
	while (ft_isdigit(unparsed[i]))
	{
		width[i] = unparsed[i];
		i++;
		inf->length++;
	}
	width[i] = '\0';
	inf->width = ft_atoi(width);
	return (i);
}
int ft_parsered_precision(t_parsered *inf, char *unparsed)
{
	char 	precision[100];
	int		i;

	i = 0;
	inf->length++;
	if (*++unparsed == '*')
	{
		inf->precision = -1;
		inf->length++;
		return (2);
	}
	while (ft_isdigit(unparsed[i]))
	{
		precision[i] = unparsed[i];
		i++;
		inf->length++;
	}
	precision[i] = '\0';
	inf->precision = ft_atoi(precision);
	return (i + 1);
}
void init(t_parsered *inf)
{
	inf->width = 0;
	inf->precision = 0;
	inf->flag_minus = 0;
	inf->flag_nul = 0;
	inf->length = 0;
	inf->type = 0;
}
t_parsered *ft_parser(char *unparsed)
{
	t_parsered	*inf;
	int			len;

	if (!(inf = (t_parsered*)malloc(sizeof *inf)))
		return (NULL);
	init (inf);
	ft_parsered_flags(inf, unparsed);
	unparsed += inf->length;
	len = ft_parsered_width(inf, unparsed);
	unparsed += len;
	inf->precision_flag = (*unparsed == '.') ? 1 : 0;
	if (*unparsed == '.')
	{
		len = ft_parsered_precision(inf, unparsed);
		unparsed += len;
	}
	if (ft_strchr("cspdiuxX%", *unparsed))
	{
		inf->type = *unparsed;
		inf->length++;
	}
	else
		inf->type = '\0';
	return (inf);
}