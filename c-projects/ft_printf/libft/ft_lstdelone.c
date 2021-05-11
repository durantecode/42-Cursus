/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 22:35:31 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/19 00:05:05 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Takes as a parameter an element and frees the
** memory of the element’s content using the function’del’ 
** given as a parameter and free the element. The memory 
** of ’next’ must not be freed. */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL)
	{
		if (del != NULL && lst->content != NULL)
			(del)(lst->content);
		free(lst);
		lst = NULL;
	}
}
