/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:20:45 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/29 18:33:53 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Deletes the head node from the list passed */

void	delete_node(t_list **stack)
{
	t_list	*aux;

	aux = *stack;
	*stack = (*stack)->next;
	free(aux->content);
	free(aux);
}

/* If there's no list, creates it and adds the first value
if it already exists, adds it to the top */

void	push(t_list **stack, int n)
{
	if (!stack)
		*stack = ft_new_stack((void *) &n, sizeof(int));
	else
		ft_lstadd_front(stack, ft_new_stack((void *) &n, sizeof(int)));
}

/* Executes push_a or push_b depending on the parameter
passed in char, then deletes the node from the original
stack */

void	ft_push(t_list **a, t_list **b, char c)
{
	int	n;

	if (c == 'a')
	{
		if (*b)
		{
			n = *(int *)(*b)->content;
			push(a, n);
			delete_node(b);
			write(1, "pa\n", 3);
		}
	}
	if (c == 'b')
	{
		if (*a)
		{
			n = *(int *)(*a)->content;
			push(b, n);
			delete_node(a);
			write(1, "pb\n", 3);
		}
	}
}
