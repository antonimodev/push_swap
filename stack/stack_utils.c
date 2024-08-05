/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:28:35 by antonimo          #+#    #+#             */
/*   Updated: 2024/08/05 13:26:27 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	fill_pile(t_stack *stacks, t_pile *piles, int ac, char **av)
{
	int	*nums;
	int	i;

	nums = malloc(ac * sizeof(int));
	if (!nums)
		error(stacks);
	i = 0;
	while (av[i])
	{
		if (!valid_av(av[i])) /*Lo hace así porque cuando ATOI da mal, te devuelve 0, y 0 es un argumento válido*/
			error(stacks);
		nums[i] = ft_atoi(av[i]);
		i++;
	}
	check_doubles(stacks, nums, ac);
	nums_ranked(nums, piles->array, ac);
	piles->bottom = ac - 1;
	free(nums);
}

bool	valid_av(char av[])
{
	int			sign;
	long long	num;

	sign = 1; /*Cambiar signo en caso de -*/
	if (*av == '\0') /*Ponemos '\0' porque av son strings*/
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
	/*comprobado que los av son '-NUMEROS' o '+NUMEROS' y no son '-' o '+'*/
	while (*av)
	{
		if (!ft_isdigit) /*cubrimos por si fuese '--' / '++' o '-LETRAS' / '+LETRAS'*/
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
