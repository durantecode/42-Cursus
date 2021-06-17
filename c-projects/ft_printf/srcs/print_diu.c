/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:04:16 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/17 19:00:31 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_fill_space_diu(int spaces, t_print *tab)
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

void	ft_print_diu(t_print *tab)
{
	int		len;
	int		digit;
	char	*str;

	digit = va_arg(tab->args, int);
	if (digit < 0)
	{
		tab->sign = 1;
		digit = -digit;
	}
	str = ft_itoa(digit);
	len = ft_strlen(str);
	if (tab->point)
	{
		if (tab->preci >= 0)
			tab->zero = 1;
		if (tab->preci >= tab->width)
			tab->dash = 0;
		if (tab->preci < len && tab->width < tab->preci)
			tab->zero = 0;
	}
	if (len > tab->width && tab->preci == -1)
	{
		if (tab->sign)
			tab->length += write(1, "-", 1);
		if (digit >= 0)
		{
			if (tab->point && digit == 0 && !tab->p_star)
			{
				free(str);
				return ;
			}
			else
				tab->length += write(1, str, len);
		}
	}
	if (!tab->width && tab->preci >= 0)
	{
		if (tab->preci == 0 && digit == 0)
		{
			free(str);
			return ;
		}
		if (tab->dash)
		{
			tab->length += write(1, str, len);
			ft_fill_space_diu(tab->preci - len, tab);
		}
		else
		{
			if (tab->sign && !tab->zero)
				tab->length += write(1, "-", 1);
			ft_fill_space_diu(tab->preci - len, tab);
			tab->length += write(1, str, len);
		}
	}
	if (tab->width >= len && tab->preci == -1)
	{
		if (digit == 0)
		{
			if (tab->point)
				ft_fill_space_diu(tab->width, tab);
			else
			{
				if (tab->dash)
				{
					tab->length += write(1, str, len);
					ft_fill_space_diu(tab->width - len, tab);
				}
				else
				{
					ft_fill_space_diu(tab->width - len, tab);
					tab->length += write(1, str, len);
				}
			}
		}
		else if (tab->dash)
		{
			if (tab->sign)
			{
				tab->length += write(1, "-", 1);
				tab->width--;
			}
			tab->length += write(1, str, len);
			if (tab->width > tab->preci)
				tab->zero = 0;
			ft_fill_space_diu(tab->width - len, tab);
		}
		else
		{
			if (tab->sign)
				ft_fill_space_diu(tab->width - len - 1, tab);
			else
				ft_fill_space_diu(tab->width - len, tab);
			if (digit > 0)
			{
				if (tab->sign && !tab->zero)
				{
					tab->length += write(1, "-", 1);
					tab->length += write(1, str, len);
				}
				else
				tab->length += write(1, str, len);
			}
		}
	}
	else if(tab->width && tab->preci >= 0)
	{
		if (tab->preci >= tab->width)
		{
			ft_fill_space_diu(tab->preci - len, tab);
			tab->length += write(1, str, len);
		}
		else if (tab->preci < tab->width)
		{
			if (tab->dash)
			{
				ft_fill_space_diu(tab->preci - len, tab);
				tab->zero = 0;
				if (tab->preci == 0 && digit == 0)
				{
					ft_fill_space(tab->width, tab);
					tab->length += tab->width;
				}
				else
				{
					tab->length += write(1, str, len);
					if (len >= tab->preci)
						ft_fill_space_diu(tab->width - len - tab->sign, tab);
					else
						ft_fill_space_diu(tab->width - tab->preci - tab->sign, tab);
				}
			}
			else
			{
				if (digit < 0)
				 	tab->sign = 0;
				tab->zero = 0;
				if (tab->sign && tab->preci == 0)
					ft_fill_space_diu(tab->width - tab->preci - len - 1, tab);
				else if (tab->sign && tab->preci > 0)
				{
					if (tab->preci <= len)
						ft_fill_space_diu(tab->width - len - 1, tab);
					else
						ft_fill_space_diu(tab->width - tab->preci - 1, tab);
				}
				else if (tab->preci < len && tab->preci > 0)
					ft_fill_space_diu(tab->width - len, tab);
				else
					ft_fill_space_diu(tab->width - tab->preci, tab);
				tab->zero = 1;
				ft_fill_space_diu(tab->preci - len, tab);
				if (tab->preci == 0 && digit == 0)
				{
					free(str);
					return ;
				}
				tab->length += write(1, str, len);
			}
		}
	}
	free(str);
}