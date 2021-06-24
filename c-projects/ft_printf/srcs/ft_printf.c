/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:49:07 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/24 17:04:28 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print	*ft_init_tab(t_print *tab)
{
	tab->width = 0;
	tab->point = 0;
	tab->preci = -1;
	tab->dash = 0;
	tab->zero = 0;
	tab->length = 0;
	tab->sign = 0;
	tab->p_star = 0;
	tab->space = 0;
	return (tab);
}

t_print	*ft_reset_tab(t_print *tab)
{
	tab->width = 0;
	tab->dash = 0;
	tab->preci = -1;
	tab->point = 0;
	tab->zero = 0;
	tab->sign = 0;
	tab->p_star = 0;
	tab->space = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	t_print		*tab;
	int			i;
	int			len;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_init_tab(tab);
	va_start(tab->args, format);
	i = -1;
	len = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_check_format(tab, format, i);
		else
			len += write(1, &format[i], 1);
	}
	va_end(tab->args);
	len += tab->length;
	free(tab);
	return (len);
}
