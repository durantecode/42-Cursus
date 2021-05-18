/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:18:21 by ldurante          #+#    #+#             */
/*   Updated: 2021/05/18 23:01:37 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	tab->length++;
	write(1, &c, 1);
}

void	ft_print_str(t_print *tab)
{
	int		len;
	char	*str;

	str = va_arg(tab->args, char *);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	tab->length += len;
}

void	ft_print_int(t_print *tab)
{
	int		len;
	int		digit;
	char	*str;

	digit = va_arg(tab->args, int);
	str = ft_itoa(digit);
	len = ft_strlen(str);
	ft_putnbr_fd(digit, 1);
	tab->length += len;
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
	while (!ft_strchr(SPECIFIERS, format[pos]))
	{
		if (format[pos] == '-')
			tab->dash = 1;
		if (format[pos] == '0')
			tab->zero = 1;
		if (format[pos] == '.')
			tab->point = 1;
		pos++;
	}
	ft_check_specifiers(tab, format, pos);
	return (pos);
}
