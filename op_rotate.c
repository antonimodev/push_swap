/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:59:27 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/17 12:29:38 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_pile *pile)
{
	if (is_full(pile))
	{
		pile->bottom = pile->top;
		pile->top = next_down(pile, pile->top);
	}
	else
	{
		pile->bottom = next_down(pile, pile->bottom);
		pile->array[pile->bottom] = pile->array[pile->top];
		pile->array[pile->top] = 0;
		pile->top = next_down(pile, pile->top);
	}
}

void	rotate_a(t_stack *stack)
{
	rotate(&stack->a);
	save_op(stack, ra);
}

void	rotate_b(t_stack *stack)
{
	rotate(&stack->b);
	save_op(stack, rb);
}

void	rotate_ab(t_stack *stack)
{
	rotate(&stack->a);
	rotate(&stack->b);
	save_op(stack, rr);
}
