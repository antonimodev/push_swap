/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_and_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:18:05 by antonimo          #+#    #+#             */
/*   Updated: 2024/08/19 10:10:43 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	sort_three_a(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = value(&stack->a, 1); /* Sacamos el valor integer del array*/
	second = value(&stack->a, 2);
	third = value(&stack->a, 3);
	if (first > second && third > second && third > first)
		swap_a(&stack->a);
	else if (first > second && third > second && first > third)
		rotate_a(&stack->a);
	else if (second > first && second > third && first > third)
		r_rotate_a(&stack->a);
	else if (second > first && second > third && third > first)
	{
		swap_a(&stack->a);
		rotate_a(&stack->a);
	}
	else if (first > second && second > third && first > third)
	{
		rotate_a(&stack->a);
		swap_a(&stack->a);
	}
}

void	sort_five_a(t_stack *stack)
{
	while (current_size(&stack->a) > 3)
	{
		if (value(&stack->a, 1) == 1 || value(&stack->a, 1) == 2)
			push_b(stack);
		else
			rotate_a(stack);
	}
	if (value(&stack->b, 1) < value(&stack->b, 2))
		swap_b(stack);
	sort_three_a(stack);
	push_a(stack);
	push_a(stack);
}
