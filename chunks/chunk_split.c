/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:45:36 by antonimo          #+#    #+#             */
/*   Updated: 2024/08/23 12:46:28 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	chunk_split(t_ps *stack, t_chunk *to_split, t_split_dest *dest)
{
}

void	init_size(t_chunk *min, t_chunk *mid, t_chunk *max)
{
	min->size = 0;
	mid->size = 0;
	max->size = 0;
}
