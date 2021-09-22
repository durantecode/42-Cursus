/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:24:04 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/22 21:25:47 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Swaps the first 2 elements at the top of stack 
passed as parameter */

int	swap(t_list **src)
{
	void	*aux;

	if (*src == NULL || ft_lstsize(*src) < 2)
		return (0);
	aux = (*src)->content;
	(*src)->content = (*src)->next->content;
	(*src)->next->content = aux;
	return (1);
}

/* Calls swap and executes sa, sb or ss 
depending on the char we passed as parameter
when we called it */

void	ft_swap(t_list **a, t_list **b, char c)
{
	if (c == 'a')
	{
		if (swap(a))
			write(1, "sa\n", 3);
	}
	if (c == 'b')
	{
		if (swap(b))
			write(1, "sb\n", 3);
	}
	if (c == 's')
	{
		if (swap(a) && swap(b))
			write(1, "ss\n", 3);
	}
}
