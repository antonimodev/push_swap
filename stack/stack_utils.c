/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:28:35 by antonimo          #+#    #+#             */
/*   Updated: 2024/07/25 12:35:21 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	fill_pile(t_stack *stacks, t_pile *piles, int ac, char **av)
{
	int	*nums;
	int	i;

	nums = malloc(ac * sizeof(int));
	i = 0;
	if (!nums)
		error(stacks);
	while (av[i])
	{
		/*if (!valid_av(av[i])) Comprobacion si es válido;
		error(stacks); libera*/
		nums[i] = ft_atoi(av[i]);
		i++;
	}
	check_doubles(&stacks, nums, ac); // Dentro de check existe error>exit que rompe la funcion, por eso no hace falta bool, con void funciona
	nums_ranked(&stacks, nums, ac);
}

void	check_doubles(t_stack *stacks, int *nums, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (i < ac)
	{
		while (j < ac)
		{
			if (nums[i] == nums[j])
			{
				free(nums);
				error(stacks);
			}
			j++;
		}
		i++;
	}
}

void	nums_ranked(t_stack *stacks, int *nums, int ac)
{
	int	i;
	int	j;
	int	count_bigger;

	i = 0;
	while (i < ac)
	{
		j = 0;
		count_bigger = 0;
		while (j < ac)
		{
			if (nums[i] >= nums[j])
				count_bigger++;
			j++;
		}
		stacks->a.array[i] = count_bigger;
		i++;
	}
}
