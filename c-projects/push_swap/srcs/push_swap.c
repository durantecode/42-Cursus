/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 21:57:04 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/22 23:52:55 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_list **a, t_list **b)
{
	int size;
	int	max_num;
	int	max_bits;
	int n;
	int i;
	int j;

	size = ft_lstsize(*a);
	max_num = size - 1;
	max_bits = 0;
	while (max_num >> max_bits)
		++max_bits;
	i = 0;
	while (++i < max_bits)
	{
		j = 0;
		while(++j < size)
		{
			n = *(int *)(*a)->content;
			if (((n >> i)&1) == 1)
				ft_rotate(a, b, 'a');
			else
				ft_push(a, b, 'b');
			print_stack(*a, *b);
		//	j++;
		}
		while(*b)
			ft_push(a, b, 'a');
		print_stack(*a, *b);
	//	++i;
	}
}