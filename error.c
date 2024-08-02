/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:49:52 by antonimo          #+#    #+#             */
/*   Updated: 2024/07/24 10:55:44 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	error(t_stack *stacks)
{
	free_stacks(stacks);
	ft_putendl_fd("An error has ocurred! exiting ...", 2);
	exit(EXIT_FAILURE);
}

void	free_stacks(t_stack *stacks)
{
	if (stacks->a.array)
		free(stacks->a.array);
	if (stacks->b.array)
		free(stacks->b.array);
	/*liberar oplist, aun no sabemos qué es*/
}
