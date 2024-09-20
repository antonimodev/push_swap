/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:51:11 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/20 12:44:22 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**init_stacks(t_stack *stacks, int ac, char **av, bool *split_flag)
{
	char	**split_av;

	split_av = av;
	if (ac == 2)
	{
		split_av = process_av(&ac, av);
		if (!split_av)
			exit(EXIT_FAILURE);
		*split_flag = true;
	}
	else
		++split_av;
	--ac;
	stacks->op_list = NULL;
	init_pile(stacks, &stacks->a, ac);
	init_pile(stacks, &stacks->b, ac);
	split_check(stacks, split_av, *split_flag);
	fill_pile(stacks, &stacks->a, ac, split_av);
	return (split_av);
}

char	**process_av(int *ac, char **av)
{
	int		i;
	char	**splitted_av;

	if (av == NULL)
		return (NULL);
	i = 0;
	splitted_av = ft_split(av[1], ' ');
	while (splitted_av[i])
		i++;
	*ac = i + 1;
	return (splitted_av);
}

void	init_pile(t_stack *stacks, t_pile *pile, int ac)
{
	pile->array = malloc(ac * sizeof(int));
	if (!pile->array)
		error(stacks);
	pile->top = 0;
	pile->bottom = 0;
	pile->size = ac;
	ft_memset(pile->array, 0, ac);
}

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
		{
			free(nums);
			error(stacks);
		}
		nums[i] = ft_atoi(av[i]);
		i++;
	}
	check_doubles(stacks, nums, ac);
	nums_ranked(nums, pile->array, ac);
	pile->bottom = ac - 1;
	free(nums);
}
