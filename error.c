/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:49:52 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/19 16:59:56 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_stack *stacks)
{
	free_stacks(stacks);
	ft_putendl_fd("An error has ocurred! exiting ...", 2);
	exit(EXIT_FAILURE);
}

void	free_split(char **split_av, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		free(split_av[i]);
		i++;
	}
	free(split_av);
}

void	free_and_exit(t_stack *stacks)
{
	free_stacks(stacks);
	exit(EXIT_SUCCESS);
}

void	free_stacks(t_stack *stacks)
{
	if (stacks->a.array)
		free(stacks->a.array);
	if (stacks->b.array)
		free(stacks->b.array);
	if (stacks->op_list)
		ft_lstclear(&stacks->op_list, NULL);
}
