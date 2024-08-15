/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:41:22 by antonimo          #+#    #+#             */
/*   Updated: 2024/08/14 13:55:09 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	sort(t_stack *stacks)
{
	if (stacks->a.size <= 1 || is_sorted(stacks)) // Creo que podemos dejar solo is_sorted
		return ;
	else if (stacks->a.size == 3)
	{
		sort_three_a(stacks);
	}
	else if (stacks->a.size == 5)
	{
		sort_five_a(stacks);
	}
	else
		/*chunk_sort(stacks);
	post_sort_optimization(stacks);*/
}

bool	is_sorted(t_stack *stacks)
{
	int	i;
	int	rank;

	i = 0;
	rank = 1;
	while (rank <= stacks->a.size)
	{
		if (stacks->a.array[i] != rank)
			return (false);
		rank++;
		i = next_down(&stacks->a, i);
	}
	return (true);
}
