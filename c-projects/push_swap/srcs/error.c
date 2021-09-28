/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:35:33 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/28 16:23:10 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Exit function, clears the list and exits the program */

void	ft_exit(t_list **a, t_list **b)
{
	ft_lstclear(a, free);
	ft_lstclear(b, free);
	exit(0);
}

/* Error management function, gets a value in e when called
and prints the error. */

void	ft_error(t_list **a)
{
	write(1, "Error\n", 6);
	ft_lstclear(a, free);
	exit(0);
}
