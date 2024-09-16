/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:13:36 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/14 16:16:30 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_aux_pf(char const *format, int *i, va_list args)
{
	int	count;

	count = 0;
	if (format[*i] == 'c')
		count = ft_putchar_pf(va_arg(args, int));
	else if (format[*i] == 's')
		count = ft_putstr_pf(va_arg(args, char *));
	else if (format[*i] == 'p')
		count = ft_putptr_pf(args);
	else if (format[*i] == 'd' || format[*i] == 'i')
		count = ft_putnbr_pf(va_arg(args, int), &count);
	else if (format[*i] == 'u')
		count = ft_putunsnbr_pf(va_arg(args, unsigned int));
	else if (format[*i] == 'x' || format[*i] == 'X')
		count = ft_hex_pf(va_arg(args, unsigned int), format[*i], &count);
	else if (format[*i] == '%')
		return (write(1, "%", 1));
	return (count);
}
