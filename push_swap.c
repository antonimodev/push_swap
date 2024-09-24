/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:40:24 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/24 11:08:18 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stacks;
	char	**split_av;
	bool	split_flag;

	split_flag = false;
	split_av = init_stacks(&stacks, ac, av, &split_flag);
	sort(&stacks, split_av, &split_flag);
	if (split_flag)
		free_split(split_av);
	free_and_exit(&stacks);
}
