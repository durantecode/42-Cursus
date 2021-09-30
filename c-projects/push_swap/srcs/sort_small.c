/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 02:29:25 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/30 14:57:35 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_list **a, t_list **b)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = *(int *)(*a)->content;
	n2 = *(int *)(*a)->next->content;
	n3 = *(int *)(*a)->next->next->content;
	if (n1 < n2 && n1 < n3 && !(n1 < n2 < n3))
	{
		ft_rev_rotate(a, b, 'a');
		ft_swap(a, b, 'a');
	}
	if (n1 < n2 && n1 > n3)
		ft_rev_rotate(a, b, 'a');
	if (n1 > n2 && n1 < n3)
		ft_swap(a, b, 'a');
	if (n1 > n2 && n1 > n3)
	{
		ft_rotate(a, b, 'a');
		if (n2 > n3)
			ft_swap(a, b, 'a');
	}
}

void	sort_four(t_list **a, t_list **b, int length)
{
	while (*(int *)(*a)->content != 3)
		ft_rotate(a, b, 'a');
	ft_push(a, b, 'b');
	sort_three(a, b);
	ft_push(a, b, 'a');
	ft_rotate(a, b, 'a');
}

void	sort_five(t_list **a, t_list **b, int length)
{
	int	pb_count;

	pb_count = 0;
	while (pb_count != 2)
	{
		if (*(int *)(*a)->content == 3 || *(int *)(*a)->content == 4)
		{
			ft_push(a, b, 'b');
			pb_count++;
		}
		else
			ft_rotate(a, b, 'a');
	}
	sort_three(a, b);
	if (*(int *)(*b)->content < *(int *)(*b)->next->content)
		ft_swap(a, b, 'b');
	ft_push(a, b, 'a');
	ft_push(a, b, 'a');
	ft_rotate(a, b, 'a');
	ft_rotate(a, b, 'a');
}

/* Sorts small stacks from 2 - 5 elements, calls the required
function depending on the size of the stack */

void	sort_small_stack(t_list **a, t_list **b, int length)
{
	if (length == 2)
		ft_swap(a, b, 'a');
	else if (length == 3)
		sort_three(a, b);
	else if (length == 4)
		sort_four(a, b, length);
	else
		sort_five(a, b, length);
}
