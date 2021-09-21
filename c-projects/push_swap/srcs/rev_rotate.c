/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:11:49 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/22 01:06:09 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_lstprev(t_list *src)
{
	int	size;
	int	i;

	i = 1;
	size = ft_lstsize(src);
	if (src == NULL)
		return (NULL);
	while (i < size - 1)
	{
		src = src->next;
		i++;
	}
	return (src);
}

void	rev_rotate(t_list **src)
{
	t_list	*prev;
	t_list	*first;
	
	if (src == NULL)
		return ;
	first = *src;
	prev = ft_lstprev(*src);
	*src = ft_lstlast(*src);
	(*src)->next = first;
	prev->next = NULL;
}

void	ft_rev_rotate(t_list **a, t_list **b, char c)
{
	if (c == 'a')
	{
		rev_rotate(a);
		write(1, "rra\n", 4);
	}
	if (c == 'b')
	{
		rev_rotate(b);
		write(1, "rrb\n", 4);
	}
	if (c == 'r')
	{
		rev_rotate(a);
		rev_rotate(b);
		write(1, "rrr\n", 4);
	}
}