/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:29:05 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/20 12:17:46 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_printf("sa\n");
}

void	swap_b(t_stack *stack)
{
	swap(&stack->b);
	ft_printf("sb\n");
}

void	swap_ab(t_stack *stack)
{
	swap(&stack->a);
	swap(&stack->b);
	ft_printf("ss\n");
}
