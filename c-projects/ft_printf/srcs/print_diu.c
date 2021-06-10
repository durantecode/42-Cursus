/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:04:16 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/09 23:09:53 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_fill_space_diu(int spaces, t_print *tab, int digit)
{
	if (tab->sign)
		tab->length += write(1, "-", 1);
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

void	ft_print_diu(t_print *tab)
{
	int		len;
	int		digit;
	char	*str;
	char	*aux;

	digit = va_arg(tab->args, int);
	if (digit < 0)
	{
		tab->sign = 1;
		tab->dash = 1;
		digit = -digit;
	}
	str = ft_itoa(digit);
	len = ft_strlen(str);
	if (tab->point)
	{
		tab->zero = 1;
		tab->dash = 0;
	}
	if (len >= tab->width && !tab->point)
	{
		if (tab->dash)
			tab->length += write(1, "-", 1);
		ft_putnbr_fd(digit, 1);
		tab->length += len;
	}
	else if (tab->dash && !tab->width)
	{
		ft_putnbr_fd(digit, 1);
		if (tab->preci && !tab->width)
			tab->width = tab->preci;
		ft_fill_space_diu(tab->width - len, tab, digit);
		tab->length += tab->width;
	}
	else
	{
		if(tab->point && tab->width)
		{
			if (tab->zero)
			{
				ft_fill_space_diu(tab->preci - len, tab, digit);
				ft_putnbr_fd(digit, 1);
			}
			if(tab->width > tab->preci)
			{
				//printf("HOLA");
				tab->zero = 0;
				if (len > tab->preci)
					ft_fill_space_diu(tab->width - len, tab, digit);
				else
					ft_fill_space_diu(tab->width - tab->preci, tab, digit);
				tab->length += tab->width;
			}
			else
				tab->length += tab->preci;
		}
		if(tab->preci && !tab->width)
		{
			ft_fill_space_diu(tab->preci - len, tab, digit);
			ft_putnbr_fd(digit, 1);
			tab->length += tab->preci;
		}
		else
		{
			ft_fill_space_diu(tab->width - len, tab, digit);
			ft_putnbr_fd(digit, 1);
			tab->length += tab->width;
		}
		//tab->length += tab->width;
	}
	free(str);
}