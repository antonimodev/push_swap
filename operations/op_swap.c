/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:29:05 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/10 14:02:06 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_pile *pile)
{
	int	tmp;

	if (pile->array[next_down(pile, pile->top)] == 0)
		return ;
	tmp = pile->array[pile->top];
	pile->array[pile->top] = pile->array[next_down(pile, pile->top)];
	pile->array[next_down(pile, pile->top)] = tmp;
}

void	swap_a(t_stack *stack)
{
	swap(&stack->a);
	save_op(stack, sa);
}

void	swap_b(t_stack *stack)
{
	swap(&stack->b);
	save_op(stack, sb);
}

void	swap_ab(t_stack *stack)
{
	swap(&stack->a);
	swap(&stack->b);
	save_op(stack, ss);
}
