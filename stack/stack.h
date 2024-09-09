/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:24:41 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/04 12:01:29 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"
# include "stdlib.h"
# include "stdbool.h"
# include "limits.h"

/* TIPOS DE DATOS PARA OPERACIONES */
enum	e_mov
{
	null_op,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	sa,
	sb,
	ss
};

/* TIPOS DE DATOS PARA CHUNKS */
enum	e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B,
};

typedef struct s_chunk
{
	enum e_loc	loc;
	int			size;
}	t_chunk;

typedef struct s_split_dest
{
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}	t_split_dest;

/* TIPOS DE DATOS EN EL STACK */
typedef struct pile
{
	int	*array;
	int	size;
	int	top; /*Top es el último elemento agregado a la pila*/
	int	bottom; /*Bottom es el elemento más antiguo de la pila*/
}	t_pile;

typedef struct stack
{
	t_pile	a;
	t_pile	b;
	t_list	*op_list; /*Lista de operaciones, aquí se supone que se guardan*/
}	t_stack;

/* STACKS */
void	init_stacks(t_stack *stacks, int ac, char **av);
char	**process_av(int *ac, char **av);

/* STACKS->UTILS*/
void	fill_pile(t_stack *stacks, t_pile *piles, int ac, char **av);
bool	valid_av(char av[]);
void	check_doubles(t_stack *stacks, int *nums, int ac);
void	nums_ranked(t_stack *stacks, int *nums, int ac);
bool	is_full(t_pile *pile);

/* ERROR */
void	error(t_stack *stacks);

/* SORT */
void	sort(t_stack *stacks);

/* SORT UTILS */
int		next_down(t_pile *pile, int index);
int		next_up(t_pile *pile, int index);

/* OPERATIONS */
void	push(t_pile *src, t_pile *dest);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
/* --- */
void	rotate(t_pile *pile);
void	rotate_a(t_pile *pile);
void	rotate_b(t_pile *pile);
void	rotate_ab(t_pile *pile);
/* --- */
void	r_rotate(t_pile *pile);
void	r_rotate_a(t_stack *stack);
void	r_rotate_b(t_stack *stack);
void	r_rotate_ab(t_stack *stack);
/* --- */
void	swap(t_pile *pile);
void	swap_a(t_pile *pile);
void	swap_b(t_pile *pile);
void	swap_ab(t_pile *pile);

/* OPTI TO THE TOP */
void	chunk_to_the_top(t_stack *stack, t_chunk *to_sort);

/* CHUNK SORT */
void	chunk_sort(t_stack *stack);
#endif