/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:49:52 by antonimo          #+#    #+#             */
/*   Updated: 2024/08/06 10:52:29 by antonimo         ###   ########.fr       */
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
	if (stacks->op_list)
		ft_lstclear(&stacks->op_list, NULL); /*lstclear limpia la lista, debido a
		que op_list es una t_list de libft*/
}
