/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:20:45 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/22 01:17:12 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Functions to execute push_a & push_b */

void	delete_node(t_list **src)
{
	t_list	*aux;

	aux = *src;
	*src = (*src)->next;
	free(aux->content);
	free(aux);
}

void	push(t_list **src, int n)
{
	if (!src)
		*src = ft_new_stack((void *) &n, sizeof(int));
	else
		ft_lstadd_front(src, ft_new_stack((void *) &n, sizeof(int)));
}

void	ft_push(t_list **a, t_list **b, char c)
{
	int n;
	
	if (c == 'a')
	{
		n = *(int *)(*b)->content;
		push(a, n);
		delete_node(b);
		write(1, "pa\n", 3);
	}
	if (c == 'b')
	{
		n = *(int *)(*a)->content;
		push(b, n);
		delete_node(a);
		write(1, "pb\n", 3);
	}
}