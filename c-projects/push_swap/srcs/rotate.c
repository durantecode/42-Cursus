/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:04:34 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/22 01:01:58 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_list **src)
{
	t_list	*first;
	
	if (*src == NULL)
		return ;
	first = *src;
	*src = first->next;
	ft_lstlast(*src)->next = first;
	first->next = NULL;
}

void	ft_rotate(t_list **a, t_list **b, char c)
{
	
	if (c == 'a')
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	if (c == 'b')
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
	if (c == 'r')
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
}