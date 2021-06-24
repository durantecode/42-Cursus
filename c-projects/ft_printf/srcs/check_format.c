/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:18:21 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/24 17:43:44 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_check_specifiers(t_print *tab, const char *format, int pos)
{
	if (tab->space)
		tab->length += write(1, " ", 1);
	if (format[pos] == 'c')
		ft_print_char(tab, 0);
	else if (format[pos] == 's')
		ft_print_str(tab);
	else if (format[pos] == 'p')
		ft_print_pointer(tab);
	else if (format[pos] == 'd' || format[pos] == 'i')
		ft_print_di(tab);
	else if (format[pos] == 'u')
		ft_print_u(tab);
	else if (format[pos] == 'x')
		ft_print_x(tab, 0);
	else if (format[pos] == 'X')
		ft_print_x(tab, 1);
	else if (format[pos] == '%')
		ft_print_char(tab, 1);
	ft_reset_tab(tab);
	return (pos);
}

int	ft_check_format(t_print *tab, const char *format, int pos)
{
	while (!ft_strchr(SPECIFIERS, format[++pos]))
	{
		if (format[pos] == ' ')
			tab->space = 1;
		else if (format[pos] == '-')
			tab->dash = 1;
		else if (format[pos] == '0')
			ft_zero(tab, format, pos);
		else if (format[pos] == '.')
			ft_point(tab, format, pos);
		else if (format[pos] == '*')
			ft_star(tab, format, pos);
		else if (ft_isdigit(format[pos]))
		{
			if (tab->point && tab->preci == -1)
				tab->preci = ft_atoi(&format[pos]);
			else if (!tab->width)
				tab->width = ft_atoi(&format[pos]);
			while (ft_isdigit(format[pos]))
				pos++;
			pos--;
		}
	}
	ft_check_specifiers(tab, format, pos);
	return (pos);
}
