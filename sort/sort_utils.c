/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:03:07 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/10 14:38:33 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	next_up(t_pile *pile, int index)
{
	if (current_size(pile) == 0)
		return (index);
	if (index == 0)
		return (pile->size - 1);
	else
		return (index - 1);
}

int	next_down(t_pile *pile, int index)
{
	if (current_size(pile) == 0)
		return (index);
	if (index == pile->size - 1)
		return (0);
	else
		return (index + 1);
}

int	current_size(t_pile *pile)
{
	if (pile->top == pile->bottom && !pile->array[pile->top])
		return (0);
	if (pile->top > pile->bottom)
		return ((pile->size - pile->top) + (pile->bottom + 1));
	else
		return (pile->bottom - pile->top + 1);
}
