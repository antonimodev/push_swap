/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:15:32 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/14 10:41:11 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(char *str)
{
	int		i;
	int		count;
	int		write_result;

	i = 0;
	count = 0;
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		write_result = write(1, &str[i], 1);
		if (write_result == -1)
			return (-1);
		count++;
		i++;
	}
	return (count);
}
