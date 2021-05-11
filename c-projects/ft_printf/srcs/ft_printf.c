/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:49:07 by ldurante          #+#    #+#             */
/*   Updated: 2021/05/11 20:28:31 by ldurante         ###   ########.fr       */
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

	va_start(tab.args, format);
	ft_init_tab(&tab)
	while (format)
	{
		if (*format == %)
	}
}
