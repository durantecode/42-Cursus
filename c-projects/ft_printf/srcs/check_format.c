/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durante <durante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:18:21 by ldurante          #+#    #+#             */
/*   Updated: 2021/05/27 18:26:54 by durante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_str(t_print *tab)
{
	int		len;
	char	*str;
	char	*aux;
	
	str = va_arg(tab->args, char *);
	len = ft_strlen(str);
	printf("PRECI: %d", tab->preci);
	if (tab->width < 0)
	{
		tab->dash = 1;
		tab->width = -tab->width;
	}	
	if (len >= tab->width && !tab->point)
	{
		ft_putstr_fd(str, 1);
		tab->length += len;
	}
	else if (tab->dash && !tab->point)
	{
		ft_putstr_fd(str, 1);
		ft_fill_space(tab->width - len, tab);
		tab->length += tab->width;
	}
	else
	{
		if (!tab->point || tab->preci)
			ft_fill_space(tab->width - len, tab);
		else
			ft_fill_space(tab->width, tab);
		tab->length += tab->width;
		aux = ft_substr(str, 0, tab->preci);
		if (tab->point)
		{
			ft_putstr_fd(aux, 1);
			if (!tab->width && tab->preci > len) 
				tab->length += len;
			else if (!tab->width && tab->preci)
				tab->length += tab->preci;
		}
		else
			ft_putstr_fd(str, 1);
		free(aux);
	}
	tab->dash = 0;
	tab->width = 0;
	tab->point = 0;
	tab->preci = 0;
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
			if (tab->point)
				tab->preci = ft_atoi(str);
			else
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
