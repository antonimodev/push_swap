/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:20:06 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/27 11:10:36 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_check(t_stack *stacks, char **split_av, bool flag)
{
	int	i;

	i = 0;
	if (flag)
	{
		while (split_av[i])
		{
			if (!valid_av(split_av[i]))
			{
				free_split(split_av);
				error(stacks);
			}
			i++;
		}
	}
}
