/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:23:14 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/28 17:23:31 by ldurante         ###   ########.fr       */
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
		ft_lstadd_back(a, ft_new_stack((void *) &not_sorted[i], sizeof(int)));
	free(array);
	free(not_sorted);
	return (a);
}

void	simplify_stack(t_list **a, t_list **b, int length)
{
	int		*array;
	int		*not_sorted;
	int		i;
	t_list	*aux;

	aux = *a;
	array = malloc(length * sizeof(int));
	if (!array)
		ft_exit(a, b);
	not_sorted = malloc(length * sizeof(int));
	if (!not_sorted)
	{
		free(array);
		ft_exit(a, b);
	}
	i = -1;
	while (++i < length)
	{
		array[i] = *(int *)aux->content;
		aux = aux->next;
	}
	ft_memcpy(not_sorted, array, length * sizeof(int));
	sort_array(array, length);
	rewrite_stack(a, not_sorted, array, length);
}
