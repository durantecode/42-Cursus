/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:24:04 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/22 00:59:58 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Functions to execute swap_a, swap_b and ss */

void	swap(t_list *src)
{
	void	*aux;
	
	if (src == NULL)
		return ;
	aux = src->content;
	src->content = src->next->content;
	src->next->content = aux;
}

void	ft_swap(t_list *a, t_list *b, char c)
{
	if (c == 'a')
	{
		swap(a);
		write(1, "sa\n", 3);
	}
	if (c == 'b')
	{
		swap(b);
		write(1, "sb\n", 3);
	}
	if (c == 's')
	{
		swap(a);
		swap(b);
		write(1, "ss\n", 3);
	}
}