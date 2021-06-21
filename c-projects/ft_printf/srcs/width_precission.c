/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precission.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:04:47 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/21 13:55:52 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	preci_no_width(t_print *tab, char *str, int len, long digit)
{
	if (!tab->width && tab->preci >= 0)
	{
		if (tab->preci == 0 && digit == 0)
		{
			return ;
		}
		if (tab->dash)
		{
			tab->length += write(1, str, len);
			ft_fill_space(tab->preci - len, tab);
		}
		else
		{
			if (tab->sign && !tab->zero)
				tab->length += write(1, "-", 1);
			ft_fill_space(tab->preci - len, tab);
			tab->length += write(1, str, len);
		}
	}
}

void	preci_and_width_nodash(t_print *tab, char *str, int len, long digit)
{
	if (digit < 0)
		tab->sign = 0;
	tab->zero = 0;
	if (tab->sign && tab->preci == 0)
		ft_fill_space(tab->width - tab->preci - len - 1, tab);
	else if (tab->sign && tab->preci > 0)
	{
		if (tab->preci <= len)
			ft_fill_space(tab->width - len - 1, tab);
		else
			ft_fill_space(tab->width - tab->preci - 1, tab);
	}
	else if (tab->preci < len && tab->preci > 0)
		ft_fill_space(tab->width - len, tab);
	else
	{
		if (tab->preci == 0 && len > 1)
			ft_fill_space(tab->width - len, tab);
		else
			ft_fill_space(tab->width - tab->preci, tab);
	}
	tab->zero = 1;
	ft_fill_space(tab->preci - len, tab);
	if (!(tab->preci == 0 && digit == 0))
		tab->length += write(1, str, len);
}

void	width_print(t_print *tab, char *str, int len, long digit)
{
	ft_fill_space(tab->preci - len, tab);
	tab->length += write(1, str, len);
}

void	preci_and_width(t_print *tab, char *str, int len, long digit)
{
	if (tab->width && tab->preci >= 0)
	{
		if (tab->preci >= tab->width)
			width_print(tab, str, len, digit);
		else if (tab->preci < tab->width)
		{
			if (tab->dash)
			{
				ft_fill_space(tab->preci - len, tab);
				tab->zero = 0;
				if (tab->preci == 0 && digit == 0)
					ft_fill_space(tab->width, tab);
				else
				{
					tab->length += write(1, str, len);
					if (len >= tab->preci)
						ft_fill_space(tab->width - len - tab->sign, tab);
					else
						ft_fill_space(tab->width - tab->preci - tab->sign, tab);
				}
			}
			else
				preci_and_width_nodash(tab, str, len, digit);
		}
	}
}
