/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:57:50 by antonimo          #+#    #+#             */
/*   Updated: 2024/08/27 13:34:30 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	r_rotate(t_pile *pile)
{
	if (is_full(pile))
	{
		pile->top = pile->bottom;
		pile->bottom = next_up(pile, pile->bottom);
	}
	else
	{
		pile->top = next_up(pile, pile->top);
		pile->array[pile->top] = pile->array[pile->bottom];
		pile->array[pile->bottom] = 0;
		pile->bottom = next_up(pile, pile->bottom);
	}
}

void	r_rotate_a(t_stack *stack)
{
	r_rotate(&stack->a);
		save_op(stack, rra);
}

void	r_rotate_b(t_stack *stack)
{
	r_rotate(&stack->b);
		save_op(stack, rrb);
}

void	r_rotate_ab(t_stack *stack)
{
	r_rotate(&stack->a);
	r_rotate(&stack->b);
		save_op(stack, rrr);
}
