/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:51:11 by antonimo          #+#    #+#             */
/*   Updated: 2024/07/22 17:00:58 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	init_stacks(t_stack *stacks, int ac, char **av)
{
	init_pile(stacks, &stacks->a, ac);
	init_pile(stacks, &stacks->b, ac);
	fill_pile(stacks, &stacks->a, ac, ++av);
	/*Aprender que es writing_mode y op_list*/
}

void	init_pile(t_stack *stacks, t_pile *pile, int ac)
{
	pile->array = malloc(ac * sizeof(t_pile));
	if (!pile->array)
		return (0);
		/*error(stacks);*/
}

void	error(t_stack *stacks)
{
	/*free_data(data); si se quiere hacer liberación manual*/
	ft_putendl_fd("An error has ocurred! exiting ...", 2);
	exit(EXIT_FAILURE);
}
