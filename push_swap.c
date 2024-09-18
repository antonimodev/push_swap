/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:40:24 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/18 14:59:03 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stacks;
	char	**split_av;

	split_av = init_stacks(&stacks, ac, av);
	sort(&stacks, split_av, ac);
	print_operations(stacks.op_list);
	exit(EXIT_SUCCESS);
}
// EN INIT STACKS DESPUES DE RELLENAR LA PILA HAY QUE LIBERAR (SPLIT) SI EL ARGUMENTO ES VÁLIDO -> ./push_swap "4 1 9"
// FALTA CUBRIR 1 FREE SI NO ES VÁLIDO -> ./push_swap 4 k 9
// SI NO ES VÁLIDO Y HAY SPLIT, HAY QUE LIBERAR SPLIT -> ./push_swap "4 1 k"
// EN EL CASO MÁS NORMAL HAY ERRORES DE MEMORIA EN FUNCIONES DE LIBFT (CREO) -> ./push_swap 4 1 9

// SI NO PASA POR SPLIT NO PUEDO HACER FREE_SPLIT