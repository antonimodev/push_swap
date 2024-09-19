/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:01:47 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/19 16:50:32 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_temp;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		lst_temp = (*lst)->next;
		if (del)
			ft_lstdelone(*lst, del);
		else
			free(*lst);
		*lst = lst_temp;
	}
}
