/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:40:24 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/10 17:48:23 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	main(int ac, char *av[])
{
	t_stack	stacks;

	init_stacks(&stacks, ac, av);
	sort(&stacks);
	print_operations();
	exit(EXIT_SUCCESS);
}
