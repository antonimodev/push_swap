/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:53:47 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/16 14:12:59 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*loc_to_stack(t_stack *stacks, enum e_loc loc)
{
	if (loc == TOP_A || loc == BOTTOM_A)
		return (&stacks->a);
	else
		return (&stacks->b);
}

int	chunk_value(t_stack *stack, t_chunk *chunk, int n)
{
	enum e_loc	loc;
	t_pile		*pile;
	int			i;

	i = 0;
	loc = chunk->loc;
	pile = loc_to_stack(stack, loc);
	if (loc == TOP_A || loc == TOP_B)
		i = pile->top;
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
		i = pile->bottom;
	if (loc == TOP_A || loc == TOP_B)
		while (--n > 0)
			i = next_down(pile, i);
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
		while (--n > 0)
			i = next_up(pile, i);
	return (pile->array[i]);
}

int	chunk_max_value(t_stack *stack, t_chunk *chunk)
{
	t_pile	*pile;
	int		size;
	int		max_value;
	int		i;

	i = 0;
	pile = loc_to_stack(stack, chunk->loc);
	size = chunk->size;
	max_value = 0;
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		i = pile->top;
	else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
		i = pile->bottom;
	while (size--)
	{
		if (pile->array[i] > max_value)
			max_value = pile->array[i];
		if (chunk->loc == TOP_A || chunk->loc == TOP_B)
			i = next_down(pile, i);
		else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
			i = next_up(pile, i);
	}
	return (max_value);
}
