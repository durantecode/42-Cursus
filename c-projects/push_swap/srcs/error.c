/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:35:33 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/28 02:05:00 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Exit function, clears the list and exits the program */

void	ft_exit(t_list **a, t_list **b, t_list **aux_stack)
{
	ft_lstclear(a, free);
	ft_lstclear(b, free);
	ft_lstclear(aux_stack, free);
	// system("leaks push_swap");
	exit(0);
}

/* Error management function, gets a value in e when called
and prints the error. */

void	ft_error(int e, t_list **a)
{
	if (e == 0)
		ft_putstr_fd("Error\nWrong argument count\n", 1);
	if (e == 1)
	{
		ft_putstr_fd("Error\nArguments must be only integers ", 1);
		ft_putstr_fd("or must start only with one sign '+' or '-'\n", 1);
	}	
	if (e == 2)
		ft_putstr_fd("Error\n0 can't be positive or negative\n", 1);
	if (e == 3)
		ft_putstr_fd("Error\nValues must no exceed MAX_INT or MIN_INT\n", 1);
	if (e == 4)
		ft_putstr_fd("Error\nDuplicated arguments\n", 1);
	ft_lstclear(a, free);
	// write(1, "Error\n", 6);
	// system("leaks push_swap");
	exit(0);
}
