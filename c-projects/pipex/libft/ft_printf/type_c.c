/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:46:48 by durante           #+#    #+#             */
/*   Updated: 2021/10/01 00:52:57 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_space(int spaces, t_print *tab)
{
	if (tab->sign && tab->zero)
		tab->length += write(1, "-", 1);
	if (tab->zero)
	{
		while (spaces-- > 0)
			tab->length += write(1, "0", 1);
	}
	else
	{
		while (spaces-- > 0)
			tab->length += write(1, " ", 1);
	}
}

void	ft_print_char(t_print *tab, int i)
{
	char	c;
	char	*str;

	if (i == 0)
		c = va_arg(tab->args, int);
	else
		c = '%';
	str = &c;
	basic_width(tab, str, 1);
}
