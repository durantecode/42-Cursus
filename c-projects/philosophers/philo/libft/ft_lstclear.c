/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:28:17 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/19 21:40:19 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Deletes and frees the given element and every
** successor of that element, using the function 
** ’del’and free(3).Finally, the pointer to the 
** list must be set to NULL */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (lst)
	{
		while (*lst)
		{
			aux = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = aux;
		}
	}
}
