/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durante <durante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:18:21 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/03 01:13:33 by durante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_int(t_print *tab)
{
	int		len;
	int		digit;
	char	*str;

	digit = va_arg(tab->args, int);
	str = ft_itoa(digit);
	len = ft_strlen(str);
	if (len >= tab->width)
	{
		ft_putnbr_fd(digit, 1);
		tab->length += len;
	}
	else if (tab->dash == 1)
	{
		ft_putnbr_fd(digit, 1);
		ft_fill_space(tab->width - len, tab);
		tab->length += tab->width;
	}
	else
	{
		write(1, "-", 1);
		ft_fill_space(tab->width - len, tab);
		ft_putnbr_fd(-digit, 1);
		tab->length += tab->width;
	}
}

int	ft_check_specifiers(t_print *tab, const char *format, int pos)
{
	if (format[pos] == 'c')
		ft_print_char(tab);
	if (format[pos] == 's')
		ft_print_str(tab);
	if (format[pos] == 'd' || format[pos] == 'i')
		ft_print_int(tab);
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
			tab->width = va_arg(tab->args, int);
		pos++;
	}
	free(str);
	free(ptr);
	ft_check_specifiers(tab, format, pos);
	return (pos);
}
