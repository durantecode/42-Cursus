/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:22:50 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/27 18:06:44 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Auxiliary function to print the stacks and see
if the operations are working properly */

void	print_aux(t_list *a, t_list *b)
{
	if (!b)
	{
		ft_putnbr_fd(*(int *)a->content, 1);
		write(1, "\n", 1);
	}	
	if (!a)
	{
		write(1, "    ", 4);
		ft_putnbr_fd(*(int *)b->content, 1);
		write(1, "   \n", 4);
	}
}

void	print_stack(t_list *a, t_list *b)
{
	write(1, "------\n", 7);
	while (a || b)
	{
		if (a && b)
		{
			ft_putnbr_fd(*(int *)a->content, 1);
			write(1, "   ", 3);
			ft_putnbr_fd(*(int *)b->content, 1);
			write(1, "   \n", 4);
		}
		else
			print_aux(a, b);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	write(1, "--- ---\n", 8);
	write(1, " A   B \n\n", 9);
}
