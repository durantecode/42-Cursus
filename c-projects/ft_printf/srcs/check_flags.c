/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 22:35:01 by durante           #+#    #+#             */
/*   Updated: 2021/06/23 21:23:01 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_zero(t_print *tab, const char *format, int pos)
{
	if (format[pos - 1] == '%' && format[pos + 1] != '-')
		tab->zero = 1;
	if (format[pos - 1] == '.' && tab->preci == -1
		&& !ft_isdigit(format[pos + 1]))
		tab->preci = 0;
	if (format[pos + 1] == '*' && format[pos + 2] == '.')
		tab->zero = 0;
}

void	ft_point(t_print *tab, const char *format, int pos)
{
	if (format[pos + 1] != '*')
		tab->point = 1;
	else if (format[pos + 1] == '*' && format[pos + 2] == 's')
		tab->point = 1;
	else if (format[pos + 1] == '*' && format[pos + 2] == 'p')
		tab->point = 1;
	else if (format[pos + 1] == '*' && format[pos + 2] == 'd')
		tab->point = 1;
	else if (format[pos + 1] == '*' && format[pos + 2] == 'i')
		tab->point = 1;
	else if (format[pos + 1] == '*' && format[pos + 2] == 'u')
		tab->point = 1;
	else if (format[pos + 1] == '*' && format[pos + 2] == 'x')
		tab->point = 1;
	else if (format[pos + 1] == '*' && format[pos + 2] == 'X')
		tab->point = 1;
	else if (format[pos + 1] == '*' && format[pos + 2] == '%')
		tab->point = 1;
}

void	ft_star(t_print *tab, const char *format, int pos)
{
	if (tab->width || tab->point)
	{
		tab->preci = va_arg(tab->args, int);
		if (tab->preci == -1)
			tab->p_star = 1;
	}
	else
		tab->width = va_arg(tab->args, int);
	if (tab->width < 0)
	{
		tab->dash = 1;
		tab->width = -tab->width;
	}
	if (tab->preci < -1)
	{
		if (format[pos + 1] == 's' && format[pos - 1] == '.')
			tab->sign = 1;
		if (format[pos + 1] == 'p' && format[pos - 1] == '.')
			tab->p_star = 1;
		tab->preci = -1;
	}
}
