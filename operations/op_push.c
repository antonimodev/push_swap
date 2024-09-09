/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:45:57 by antonimo          #+#    #+#             */
/*   Updated: 2024/08/08 16:23:42 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_pile *src, t_pile *dest)
{
	int	dest_index;

	if (is_full(dest))
		return ;
	dest_index = next_up(dest, dest->top);
	dest->array[dest_index] = src->array[src->top];
	dest->top = dest_index;
	src->array[src->top] = 0;
	src->top = next_down(src, src->top);
}

void	push_a(t_stack *stack)
{
	push(&stack->a, &stack->b);
	save_op(stack, pa);
}
void	push_b(t_stack *stack)
{
	push(&stack->b, &stack->a);
	save_op(stack, pb);
}
