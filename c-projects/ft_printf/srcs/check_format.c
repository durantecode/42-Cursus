/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:18:21 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/03 16:11:14 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_check_specifiers(t_print *tab, const char *format, int pos)
{
	if (format[pos] == 'c')
		ft_print_char(tab);
	if (format[pos] == 's')
		ft_print_str(tab);
	if (format[pos] == 'p')
		ft_print_diu(tab);
	if (format[pos] == 'd' || format[pos] == 'i')
		ft_print_diu(tab);
	ft_reset_tab(tab);
	return (pos);
}

void	ft_preci(t_print *tab, const char *format, int pos, char *ptr)
{
	char	*aux;

	aux = ft_strjoin(ptr, &format[pos]);
	ptr = aux;
	tab->preci += ft_atoi(ptr);
	free(ptr);
}

void	ft_width(t_print *tab, const char *format, int pos, char *str)
{
	char	*aux;

	aux = ft_strjoin(str, &format[pos]);
	str = aux;
	tab->width += ft_atoi(str);
	free(str);
}

int	ft_check_format(t_print *tab, const char *format, int pos)
{
	char	*str;
	char	*ptr;

	str = ft_strdup("");
	ptr = ft_strdup("");
	while (!ft_strchr(SPECIFIERS, format[pos]))
	{
		if (format[pos] == '-')
			tab->dash = 1;
		else if (format[pos] == '0' && format[pos - 1] == '%')
			tab->zero = 1;
		else if (format[pos] == '.' && format[pos + 1] != '*')
			tab->point = 1;
		else if (ft_isdigit(format[pos]))
		{
			if (tab->point)
				ft_preci(tab, format, pos, ptr);
			else
				ft_width(tab, format, pos, str);
		}
		else if (format[pos] == '*')
		{
			tab->width = va_arg(tab->args, int);
			if (tab->width < 0)
			{
				tab->dash = 1;
				tab->width = -tab->width;
			}
		}	
		pos++;
	}
	free(str);
	free(ptr);
	ft_check_specifiers(tab, format, pos);
	return (pos);
}
