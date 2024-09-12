/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_optimization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:22:31 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/12 13:53:24 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_to_the_top(t_stack *stack, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_B && current_size(&stack->b) == to_sort->size)
		to_sort->loc = TOP_B;
	if (to_sort->loc == BOTTOM_A && current_size(&stack->a) == to_sort->size)
		to_sort->loc = TOP_A;
}
