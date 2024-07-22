/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:24:41 by antonimo          #+#    #+#             */
/*   Updated: 2024/07/22 15:56:46 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"
# include "stdlib.h"

typedef struct pile
{
	int	*array;
	int	size;
	/*int top
	int bottom*/
}	t_pile;

typedef struct stack
{
	t_pile	a;
	t_pile	b;
	/* t_list	*op_list;
	bool	writing_mode;*/
}	t_stack;
#endif