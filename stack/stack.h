/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:24:41 by antonimo          #+#    #+#             */
/*   Updated: 2024/08/08 13:23:09 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"
# include "stdlib.h"
# include "stdbool.h"
# include "limits.h"

typedef struct pile
{
	int	*array;
	int	size;
	int	top; /*Es un índice que indica el elemento más reciente agregado*/
	int	bottom; /*Es un índice que indica el elemento más antiguo*/
}	t_pile;

typedef struct stack
{
	t_pile	a;
	t_pile	b;
	t_list	*op_list; /*Lista de operaciones, aquí se supone que se guardan*/
	bool	writing_mode; /*permite o no permite que se registren operaciones
	en la lista*/
}	t_stack;

/* STACKS */
void	init_stacks(t_stack *stacks, int ac, char **av, bool writing_mode);

/* STACKS->UTILS*/
void	fill_pile(t_stack *stacks, t_pile *piles, int ac, char **av);
void	check_doubles(t_stack *stacks, int *nums, int ac);
void	nums_ranked(t_stack *stacks, int *nums, int ac);
bool	valid_av(char av[]);

/* ERROR */
void	error(t_stack *stacks);

/**/
bool	is_full(t_pile *pile);

#endif