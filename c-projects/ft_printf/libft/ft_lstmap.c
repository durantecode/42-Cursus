/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:35:57 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/22 13:37:38 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Iterates the list ’lst’ and applies the function’f’ 
to the content of each element. Creates a newlist 
resulting of the successive applications ofthe function ’f’.
The ’del’ function is used to delete the content of an element if needed */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*aux_lst;

	if (!lst || !f)
		return (NULL);
	aux_lst = ft_lstnew(f(lst->content));
	if (!aux_lst)
		return (NULL);
	new_lst = aux_lst;
	lst = lst->next;
	while (lst)
	{
		aux_lst->next = ft_lstnew(f(lst->content));
		if (!aux_lst->next)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		aux_lst = aux_lst->next;
		lst = lst->next;
	}
	return (new_lst);
}
