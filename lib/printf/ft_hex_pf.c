/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:24:45 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/14 14:11:03 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_checkhex_pf(char x_or_X)
{
	char	*base_character;

	if (x_or_X == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	return (base_character);
}

int	ft_hex_pf(unsigned int number, char x_or_X, int *count)
{
	char			str[25];
	char			*base_character;
	int				i;

	base_character = ft_checkhex_pf(x_or_X);
	i = 0;
	if (number == 0)
	{
		if (ft_putchar_pf('0') == -1)
			return (-1);
		(*count)++;
	}
	while (number != 0)
	{
		str[i] = base_character [number % 16];
		number = number / 16;
		i++;
	}
	while (i--)
	{
		if (ft_putchar_pf(str[i]) == -1)
			return (-1);
		(*count)++;
	}
	return (*count);
}
