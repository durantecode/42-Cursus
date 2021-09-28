/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 00:29:17 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/28 01:44:20 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*sort_array(int *array, int length)
{
	int	i;
	int	j;
	int	aux;

	i = -1;
	while (++i < length)
	{
		j = i + 1;
		while (j < length)
		{
			if (array[i] > array[j])
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
			}
			j++;
		}
	}
	return (array);
}

t_list	**rewrite_stack(t_list **a, int *not_sorted, int *array, int length)
{
	int	i;
	int	j;
	int	n;

	i = -1;
	while (++i < length)
	{
		j = -1;
		while (++j < length)
		{
			if (not_sorted[i] == array[j])
			{
				not_sorted[i] = j;
				break ;
			}	
		}
	}
	ft_lstclear(a, free);
	i = -1;
	while (++i < length)
	{
		n = not_sorted[i];
		ft_lstadd_back(a, ft_new_stack((void *) &n, sizeof(int)));
	}
	return (a);
}

void	simplify_stack(t_list **a, int length)
{
	int		*array;
	int		*not_sorted;
	int		i;

	array = malloc(length * sizeof(int));
	not_sorted = malloc(length * sizeof(int));
	if (!array)
		array = NULL;
	if (!not_sorted)
		not_sorted = NULL;
	i = -1;
	while (++i < length)
	{
		array[i] = *(int *)(*a)->content;
		free((*a)->content);
		free((*a));
		*a = (*a)->next;
	}
	ft_memcpy(not_sorted, array, length * sizeof(int));
	sort_array(array, length);
	rewrite_stack(a, not_sorted, array, length);
	free(array);
	free(not_sorted);
}

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
	while (++i <= bits)
	{
		j = -1;
		while (++j < length)
		{
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
