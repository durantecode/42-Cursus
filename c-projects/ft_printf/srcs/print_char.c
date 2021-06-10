/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:46:48 by durante           #+#    #+#             */
/*   Updated: 2021/06/10 12:30:30 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_fill_space(int spaces, t_print *tab)
{
	if (tab->zero)
	{
		while (spaces-- > 0)
			write(1, "0", 1);
	}
	else 
	{
		while (spaces-- > 0)
			write(1, " ", 1);
	}
}

void	ft_print_char(t_print *tab, int i)
{
	char	c;

	if (i == 0)
		c = va_arg(tab->args, int);
	else
		c = '%';
	if (tab->dash)
	{
		tab->length += write(1, &c, 1);
		ft_fill_space(tab->width - 1, tab);
	}
	else
	{
		ft_fill_space(tab->width - 1, tab);
		tab->length += write(1, &c, 1);
	}
	if (tab->width)
		tab->length += tab->width - 1;
}
