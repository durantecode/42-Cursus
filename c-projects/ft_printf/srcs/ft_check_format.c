/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:18:21 by ldurante          #+#    #+#             */
/*   Updated: 2021/05/26 19:02:23 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_fill_space(int spaces, t_print *tab)
{
	if (tab->zero == 1)
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

void	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	if (tab->width < 0)
	{
		tab->dash = 1;
		tab->width = -tab->width;
	}	
	if (tab->dash == 1)
	{
		write(1, &c, 1);
		ft_fill_space(tab->width - 1, tab);
		if (tab->width)
			tab->length += tab->width;
		else
			tab->length++;
	}
	else
	{
		ft_fill_space(tab->width - 1, tab);
		write(1, &c, 1);
		if (tab->width)
			tab->length += tab->width;
		else
			tab->length++;
	}
	tab->dash = 0;
	tab->width = 0;
}

void	ft_print_str(t_print *tab)
{
	int		len;
	char	*str;

	str = va_arg(tab->args, char *);
	len = ft_strlen(str);
	if (len >= tab->width)
	{
		ft_putstr_fd(str, 1);
		tab->length += len;
	}
	else if (tab->dash == 1)
	{
		ft_putstr_fd(str, 1);
		ft_fill_space(tab->width - len, tab);
		tab->length += tab->width;
	}
	else
	{
		ft_fill_space(tab->width - len, tab);
		ft_putstr_fd(str, 1);
		tab->length += tab->width;
	}
	tab->dash = 0;
	tab->width = 0;
}

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
	return (pos);
}

int	ft_check_format(t_print *tab, const char *format, int pos)
{
	char	*str;
	char	*aux;

	str = ft_strdup("");
	while (!ft_strchr(SPECIFIERS, format[pos]))
	{
		if (format[pos] == '-')
			tab->dash = 1;
		else if (format[pos] == '0' && format[pos - 1] == '%')
			tab->zero = 1;
		else if (format[pos] == '.')
			tab->point = 1;
		else if (ft_isdigit(format[pos]))
		{
			aux = ft_strjoin(str, &format[pos]);
			free(str);
			str = aux;
			tab->width = ft_atoi(str);
		}
		else if (format[pos] == '*')
			tab->width = va_arg(tab->args, int);
		pos++;
	}
	free(str);
	ft_check_specifiers(tab, format, pos);
	return (pos);
}
