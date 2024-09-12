/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_to_the_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:22:31 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/10 10:08:10 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	chunk_to_the_top(t_stack *stack, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_B && current_size(&stack->b) == to_sort->size)
		to_sort->loc = TOP_B;
	if (to_sort->loc == BOTTOM_A && current_size(&stack->a) == to_sort->size)
		to_sort->loc = TOP_A;
}

int	chunk_value(t_stack *stack, t_chunk *chunk, int n) /*Revisar esta, 
es similar a la funcion value*/
{
	enum e_loc	loc;
	t_pile		*pile;
	int			i;

	loc = chunk->loc;
	pile = loc_to_pile(stack, loc);
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

t_pile	*loc_to_pile(t_stack *stack, enum e_loc loc)
{
	if (loc == TOP_A || loc == BOTTOM_A)
		return (&stack->a);
	else
		return (&stack->b);
}
