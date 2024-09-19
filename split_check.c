/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:20:06 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/19 12:12:55 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_check(t_stack *stacks, char **split_av, int ac, bool flag)
{
	int	i;

	i = 0;
	if (flag)
	{
		while (split_av[i])
		{
			if (!valid_av(split_av[i]))
			{
				free_split(split_av, ac);
				error(stacks);
			}
			i++;
		}
	}
}

void	finish(t_stack *stacks)
{
	if (stacks->a.array)
		free(stacks->a.array);
	if (stacks->b.array)
		free(stacks->b.array);
	if (stacks->op_list)
		free(stacks->op_list);
	exit(EXIT_SUCCESS);
}
