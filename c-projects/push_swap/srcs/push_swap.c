/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 21:57:04 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/28 01:41:56 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list **aux_stack, int length)
{
	int	i;
	int	n1;
	int	n2;

	i = -1;
	while (++i < length - 1)
	{
		n1 = *(int *)(*aux_stack)->content;
		n2 = *(int *)(*aux_stack)->next->content;
		if (n1 > n2)
			return (0);
		free((*aux_stack)->content);
		free((*aux_stack));
		*aux_stack = (*aux_stack)->next;
	}
	return (1);
}

int	push_swap(t_list **a, t_list **b, t_list **aux_stack)
{
	int	length;

	length = ft_lstsize(*a);
	if (is_sorted(aux_stack, length))
		return (0);
	simplify_stack(a, length);
	if (length <= 5)
		sort_small_stack(a, b, length);
	else
		sort_big_stack(a, b, length);
	return (0);
}
