/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:15:16 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/16 10:19:29 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* int	ft_putnbr_pf(int number, int *count)
{
	int	digit;

	if (number == -2147483648)
	{
		if (ft_putstr_pf("-2147483648") == -1)
			return (-1);
		(*count) += 11;
		return (*count);
	}
	if (number < 0)
	{
		if (ft_putchar_pf('-') == -1)
			return (-1);
		number = -number;
		(*count)++;
	}
	if (number > 9)
		ft_putnbr_pf(number / 10, count);
	digit = (number % 10) + '0';
	if (ft_putchar_pf(digit) == -1)
		return (-1);
	(*count)++;
	return (*count);
} */
static int	ft_checkintmin_pf(void)
{
	int	number;

	number = ft_putstr_pf("-2147483648");
	if (number == -1)
		return (-1);
	return (11);
}

int	ft_putnbr_pf(int number, int *count)
{
	if (number == -2147483648)
	{
		if (ft_checkintmin_pf() == -1)
			return (-1);
		(*count) += 11;
		return (*count);
	}
	if (number < 0 && number != -2147483648)
	{
		if (ft_putchar_pf('-') == -1)
			return (-1);
		number = -number;
		(*count)++;
	}
	if (number > 9)
	{
		if (ft_putnbr_pf(number / 10, count) == -1)
			return (-1);
	}
	if (ft_putchar_pf((number % 10) + '0') == -1)
		return (-1);
	(*count)++;
	return (*count);
}
