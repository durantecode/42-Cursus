/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durante <durante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:18:21 by ldurante          #+#    #+#             */
/*   Updated: 2021/05/26 01:20:11 by durante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put_space(int spaces)
{
	while (spaces-- > 0)
		write(1, " ", 1);
}

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
	if (len >= tab->width)
	{
		ft_putstr_fd(str, 1);
		tab->length += len;
	}
	else
	{
		ft_put_space(tab->width - len);
		ft_putstr_fd(str, 1);
		tab->length += tab->width;
	}

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
	char	*str;
	
	str = "";
	while (!ft_strchr(SPECIFIERS, format[pos]))
	{
		if (format[pos] == '-')
			tab->dash = 1;
		if (format[pos] == '0')
			tab->zero = 1;
		if (format[pos] == '.')
			tab->point = 1;
		if (ft_isdigit(format[pos]))
		{
			str = ft_strjoin(str, &format[pos]);
			tab->width = ft_atoi(str);
		}
		pos++;
	}
	ft_check_specifiers(tab, format, pos);
	return (pos);
}
