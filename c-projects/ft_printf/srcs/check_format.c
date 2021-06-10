/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:18:21 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/09 13:15:02 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_check_specifiers(t_print *tab, const char *format, int pos)
{
	if (format[pos] == 'c')
		ft_print_char(tab, 0);
	if (format[pos] == 's')
		ft_print_str(tab);
	if (format[pos] == 'p')
		ft_print_diu(tab);
	if (format[pos] == 'd' || format[pos] == 'i')
		ft_print_diu(tab);
	else if (format[pos] == '%')
		ft_print_char(tab, 1);
	ft_reset_tab(tab);
	return (pos);
}

int	ft_check_format(t_print *tab, const char *format, int pos)
{
	while (!ft_strchr(SPECIFIERS, format[pos]))
	{
		if (format[pos] == '-')
			ft_dash(tab, format, pos);
		else if (format[pos] == '0')
			ft_zero(tab, format, pos);
		else if (format[pos] == '.')
			ft_point(tab, format, pos);
		else if (format[pos] == '*')
			ft_star(tab, format, pos);
		else if (ft_isdigit(format[pos]))
		{
			if (tab->point && !tab->preci)
				tab->preci += ft_atoi(&format[pos]);
			else if (!tab->width)
				tab->width += ft_atoi(&format[pos]);
		}
		pos++;
	}
	ft_check_specifiers(tab, format, pos);
	return (pos);
}
