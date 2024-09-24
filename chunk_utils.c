/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:53:47 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/24 13:51:45 by antonimo         ###   ########.fr       */
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
	t_pile		*pile;
	int			i;

	i = 0;
	pile = loc_to_stack(stack, chunk->loc);
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		i = pile->top;
	else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
		i = pile->bottom;
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		while (--n > 0)
			i = next_down(pile, i);
	else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
		while (--n > 0)
			i = next_up(pile, i);
	return (pile->array[i]);
}

int	chunk_max_value(t_stack *stack, t_chunk *chunk)
{
	t_pile	*pile;
	int		chunk_size;
	int		max_value;
	int		i;

	i = 0;
	pile = loc_to_stack(stack, chunk->loc);
	chunk_size = chunk->size;
	max_value = 0;
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		i = pile->top;
	else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
		i = pile->bottom;
	while (chunk_size--)
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
