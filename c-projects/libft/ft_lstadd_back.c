/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:17:29 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/16 12:44:28 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Adds the element ’new’ at the end of the list */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*x;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	x = *lst;
	while (x->next != NULL)
		x = x->next;
	x->next = new;
}
