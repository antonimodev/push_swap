/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:28:35 by antonimo          #+#    #+#             */
/*   Updated: 2024/08/07 12:09:38 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	fill_pile(t_stack *stacks, t_pile *pile, int ac, char **av)
{
	int	*nums;
	int	i;

	nums = malloc(ac * sizeof(int));
	if (!nums)
		error(stacks);
	i = 0;
	while (av[i])
	{
		if (!valid_av(av[i]))
			error(stacks);
		nums[i] = ft_atoi(av[i]);
		i++;
	}
	check_doubles(stacks, nums, ac);
	nums_ranked(nums, pile->array, ac);
	pile->bottom = ac - 1;
	free(nums);
}

bool	valid_av(char av[])
{
	int			sign;
	long long	num;

	sign = 1;
	if (*av == '\0')
		return (false);
	if (*av == '-' || av == '+')
	{
		if (*av == '-')
			sign = -1;
		av++;
		if (*av == '\0')
			return (false);
	}
	num = 0;
	while (*av)
	{
		if (!ft_isdigit)
			return (false);
		num = num * 10 + (*av - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && num < INT_MIN))
			return (false);
		*av++;
	}
	return (true);
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

/* Nums ranked calcula el orden en el que tiene que ir cada valor y lo almacena en la pila*/
void	nums_ranked(int *nums, int pile[], int ac)
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
		pile[i] = count_bigger;
		i++;
	}
}

bool	is_full(t_pile *pile)
{
	return (pile->size == current_size(pile));
}
