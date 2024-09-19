/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:40:24 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/19 14:24:15 by antonimo         ###   ########.fr       */
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
	sort(&stacks, split_av, ac, &split_flag);
	print_operations(stacks.op_list);
	if (split_flag)
		free_split(split_av, ac);
	finish(&stacks);
}

/*FUNCIONA

• VACIO
• "VACIO"
• ke
• ke sad
• "ke"
• "ke sad"
------
•  1
• "1"
• 1 2 3 (ORDENADOS)
• 1 2 3 4 5 (+5) (ORDENADOS)
•  1 ke sad
•  1 ke sad (+5)
• "1 ke sad"
• "1 ke sad" (+5)

NO FUNCIONA

• 4 9 8
• "4 9 8"
• "1 2 3" (ORDENADOS)*/