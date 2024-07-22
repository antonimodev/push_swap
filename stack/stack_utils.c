/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:28:35 by antonimo          #+#    #+#             */
/*   Updated: 2024/07/22 16:39:22 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	fill_pile(t_stack stacks, t_pile piles, int ac, char **av)
{
	int	*nums;
	int	i;

	nums = malloc(ac * sizeof(int));
	i = 0;
	if (!nums)
		return (0); // error(stacks);
	while (av[i])
	{
		nums[i] = ft_atoi(av[i]);
		i++;
	}
}
