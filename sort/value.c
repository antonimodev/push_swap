/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:21:20 by antonimo          #+#    #+#             */
/*   Updated: 2024/08/19 10:21:28 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	value(t_pile *pile, int n)
{
	int	i;

	i = pile->top;
	while (--n > 0)
		i = next_down(pile, i);
	return (pile->array[i]);
}
