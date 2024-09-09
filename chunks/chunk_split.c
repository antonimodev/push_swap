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

void	chunk_split(t_ps *stack, t_chunk *to_split, t_split_dest *dest)
{
	int	pivot_1;
	int	pivot_2;
	int	max_value;
	int	next_value;

	pivot_1 = 0;
	pivot_2 = 0;
	dest->min.size = 0;
	dest->mid.size = 0;
	dest->max.size = 0;
	split_loc(to_split->loc, &dest->min, &dest->mid, &dest->max);
	set_pivots(to_split->loc, to_split->size, &pivot_1, &pivot_2);
	max_value = chunk_max_value(data, to_split);
	while (to_split->size--)
	{
		next_value = chunk_value(data, to_split, 1);
		if (next_value > max_value - pivot_2)
			dest->max.size += move_from_to(data, to_split->loc, dest->max.loc);
		else if (next_value > max_value - pivot_1)
			dest->mid.size += move_from_to(data, to_split->loc, dest->mid.loc);
		else
			dest->min.size += move_from_to(data, to_split->loc, dest->min.loc);
	}
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

void	set_pivots(enum e_loc loc, int crt_size, int *pivot_1, int *pivot_2)
{
	*pivot_2 = crt_size / 3;
	if (loc == TOP_A || loc == BOTTOM_A)
		*pivot_1 = 2 * crt_size / 3;
	if (loc == TOP_B || loc == BOTTOM_B)
		*pivot_1 = crt_size / 2;
}
