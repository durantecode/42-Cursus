/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durante <durante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:46:48 by durante           #+#    #+#             */
/*   Updated: 2021/06/03 00:44:42 by durante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_fill_space(int spaces, t_print *tab)
{
	if (tab->zero == 1)
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

void	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	if (tab->width < 0)
	{
		tab->dash = 1;
		tab->width = -tab->width;
	}	
	if (tab->dash)
	{
		write(1, &c, 1);
		ft_fill_space(tab->width - 1, tab);
	}
	else
	{
		ft_fill_space(tab->width - 1, tab);
		write(1, &c, 1);
	}
	if (tab->width)
		tab->length += tab->width;
	else
		tab->length++;
}
