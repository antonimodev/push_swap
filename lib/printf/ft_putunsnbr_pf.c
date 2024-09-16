/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr_pf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:15:40 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/14 14:14:23 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsnbr_pf(unsigned int number)
{
	int				i;
	int				count;
	char			buffer[10];

	i = 0;
	count = 0;
	if (number == 0)
	{
		count++;
		if (ft_putchar_pf('0') == -1)
			return (-1);
	}
	while (number > 0)
	{
		buffer[i++] = (number % 10) + '0';
		number = number / 10;
	}
	while (i > 0)
	{
		i--;
		count++;
		if (ft_putchar_pf(buffer[i]) == -1)
			return (-1);
	}
	return (count);
}
