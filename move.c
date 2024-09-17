/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:58:58 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/17 14:12:35 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_from_to(t_stack *stack, enum e_loc from, enum e_loc to)
{
	if (from == TOP_A)
		move_from_top_a(stack, to);
	else if (from == TOP_B)
		move_from_top_b(stack, to);
	else if (from == BOTTOM_A)
		move_from_bottom_a(stack, to);
	else if (from == BOTTOM_B)
		move_from_bottom_b(stack, to);
	return (1);
}

void	move_from_top_a(t_stack *stack, enum e_loc to)
{
	if (to == TOP_B)
		push_b(stack);
	else if (to == BOTTOM_A)
		rotate_a(stack);
	else if (to == BOTTOM_B)
	{
		push_b(stack);
		rotate_b(stack);
	}
}

void	move_from_bottom_a(t_stack *stack, enum e_loc to)
{
	if (to == TOP_A)
		r_rotate_a(stack);
	else if (to == TOP_B)
	{
		r_rotate_a(stack);
		push_b(stack);
	}
	else if (to == BOTTOM_B)
	{
		r_rotate_a(stack);
		push_b(stack);
		rotate_b(stack);
	}
}

void	move_from_top_b(t_stack *stack, enum e_loc to)
{
	if (to == TOP_A)
		push_a(stack);
	else if (to == BOTTOM_B)
		rotate_b(stack);
	else if (to == BOTTOM_A)
	{
		push_a(stack);
		rotate_a(stack);
	}
}

void	move_from_bottom_b(t_stack *stack, enum e_loc to)
{
	if (to == TOP_B)
		r_rotate_b(stack);
	else if (to == TOP_A)
	{
		r_rotate_b(stack);
		push_a(stack);
	}
	else if (to == BOTTOM_A)
	{
		r_rotate_b(stack);
		push_a(stack);
		rotate_a(stack);
	}
}
