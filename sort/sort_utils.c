/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:03:07 by antonimo          #+#    #+#             */
/*   Updated: 2024/08/09 10:43:10 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	next_up(t_pile *pile, int index) /*Considerando la pila en vertical, mueve hacia arriba el indice*/
{
	if (current_size(pile) == 0)
		return (index);
	if (index == 0)
		return (pile->size - 1);
	else
		return (index - 1);
}

int	next_down(t_pile *pile, int index) /*Considerando la pila en vertical, mueve hacia abajo el indice*/
{
	if (current_size(pile) == 0) /*Si la pila esta vacía*/
		return (index);
	if (index == pile->size - 1) /*Si estamos en el último elemento*/
		return (0);
	else
		return (index + 1); /*avanzamos el índice*/
}

int	current_size(t_pile *pile)
{
	if (pile->top == pile->bottom && pile->array[pile->top] == 0) /*Si está vacía*/
		return (0);
	if (pile->top > pile->bottom) /*Tamaño actual de elementos entre top y bottom*/
		return ((pile->size - pile->top) + (pile->bottom + 1));
	else
		return (pile->bottom - pile->top + 1); /*aprender qué es esto*/
}
