/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:45:36 by antonimo          #+#    #+#             */
/*   Updated: 2024/08/27 12:17:32 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	chunk_split(t_stack *stack, t_chunk *to_split, t_split_dest *dest)
{
}

void	split_loc(enum e_loc loc, t_chunk *min, t_chunk *mid, t_chunk *max)
{
	if (loc == TOP_A)
	{
		min = BOTTOM_B;
		mid = TOP_B;
		max = BOTTOM_A;
	}
	else if (loc == TOP_B)
	{
		min = BOTTOM_B;
		mid = BOTTOM_A;
		max = TOP_A;
	}
	else if (loc == BOTTOM_A)
	{
		min = BOTTOM_B;
		mid = TOP_B;
		max = TOP_A;
	}
	else if (loc == BOTTOM_B)
	{
		min = TOP_B;
		mid = BOTTOM_A;
		max = TOP_A;
	}
}
void	init_size(t_chunk *min, t_chunk *mid, t_chunk *max) /* Inicializar splitted chunks*/
{
	min->size = 0;
	mid->size = 0;
	max->size = 0;
}
