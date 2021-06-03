/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:04:16 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/03 17:12:30 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_diu(t_print *tab)
{
	int		len;
	int		digit;
	char	*str;
	char	*aux;

	digit = va_arg(tab->args, int);
	str = ft_itoa(digit);
	len = ft_strlen(str);
	if (tab->point && tab->width)
	{
		tab->zero = 1;
		tab->dash = 0;
		//tab->width = tab->preci;
	}
	if (len >= tab->width && !tab->point)
	{
		ft_putnbr_fd(digit, 1);
		tab->length += len;
	}
	else if (tab->dash)
	{
		ft_putnbr_fd(digit, 1);
		if (tab->preci && !tab->width)
			tab->width = tab->preci;
		ft_fill_space(tab->width - len, tab);
		tab->length += tab->width;
	}
	else
	{
		if(tab->point && tab->width)
			ft_fill_space(tab->preci - len, tab);
		if(tab->preci)
		{
			ft_putstr_fd(str, 1);
			tab->zero = 0;
			ft_fill_space(tab->preci - len, tab);
		}
		tab->length += tab->width;
	}
	free(str);
}