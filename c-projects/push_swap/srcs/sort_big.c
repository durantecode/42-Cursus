/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 00:29:17 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/29 18:54:53 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Executes the algorithm "Radix sort" using the bitwise operators
>> and &. We take multiples of two and pass them to b while rotating 
the others, then bring them back to a and right-shift the first bit
and start again. */

void	sort_big_stack(t_list **a, t_list **b, int length)
{
	int	bits;
	int	n;
	int	i;
	int	j;

	bits = 0;
	while ((length - 1) >> bits != 0)
		bits++;
	i = -1;
	while (++i < bits)
	{
		j = -1;
		while (++j < length)
		{
			if (is_sorted(a, ft_lstsize(*a)))
				break ;
			n = *(int *)(*a)->content;
			if (((n >> i) & 1) == 1)
				ft_rotate(a, b, 'a');
			else
				ft_push(a, b, 'b');
		}
		while (*b)
			ft_push(a, b, 'a');
	}
}
