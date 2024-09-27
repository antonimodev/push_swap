/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:49:52 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/27 11:11:28 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_stack *stacks)
{
	free_stacks(stacks);
	ft_putendl_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_split(char **split_av)
{
	int	i;

	i = 0;
	while (split_av[i])
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
}
