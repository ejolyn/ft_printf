/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:28:42 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/26 18:30:18 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void process_ptr(va_list *argptr, t_parsered *inf)
{
	void	*ptr;
	int		len;

	inf->width = 0;
	len = 0;
	ptr = va_arg(*argptr, void*);
	write (1, ptr, len);
}