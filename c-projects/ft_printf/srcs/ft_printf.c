/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:49:07 by ldurante          #+#    #+#             */
/*   Updated: 2021/05/18 21:30:37 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print	*ft_init_tab(t_print *tab)
{
	tab->width = 0;
	tab->preci = 0;
	tab->zero = 0;
	tab->point = 0;
	tab->sign = 0;
	tab->length = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->percen = 0;
	tab->space = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	t_print		tab;
	int			i;
	int			len;

	ft_init_tab(&tab);
	va_start(tab.args, format);
	i = -1;
	len = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_check_format(&tab, format, i + 1);
		else
		{
			write(1, &format[i], 1);
			len++;
		}
	}
	va_end(tab.args);
	len = len + tab.length;
	return (len);
}
