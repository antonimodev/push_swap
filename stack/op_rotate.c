/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:59:27 by antonimo          #+#    #+#             */
/*   Updated: 2024/08/08 16:58:20 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
	/*if (stack->writing_mode)
		save_op*/
}

void	rotate_b(t_stack *stack)
{
	rotate(&stack->b);
	/*if (stack->writing_mode)
		save_op*/
}

void	rotate_ab(t_stack *stack)
{
	rotate(&stack->a);
	rotate(&stack->b);
	/*if (stack->writing_mode)
		save_op*/
}
