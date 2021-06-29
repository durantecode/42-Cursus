/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_diu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:04:16 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/29 22:30:27 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	update_tab_diux(t_print *tab, int len)
{
	if (tab->point)
	{
		if (tab->preci >= 0)
			tab->zero = 1;
		if (tab->preci >= tab->width)
			tab->dash = 0;
		if (tab->preci < len && tab->width < tab->preci)
			tab->zero = 0;
	}
}

void	ft_print_di(t_print *tab)
{
	int		len;
	long	digit;
	char	*str;

	digit = va_arg(tab->args, int);
	if (digit < 0)
	{
		if (digit == -2147483648)
			tab->sign = 0;
		else
			tab->sign = 1;
		digit = -digit;
	}
	str = ft_itoa(digit);
	len = ft_strlen(str);
	if (digit == 0 && tab->preci == 0 && tab->width == 1)
		len = 0;
	update_tab_diux(tab, len);
	len_width_nopreci(tab, str, len, digit);
	width_len_nopreci(tab, str, len, digit);
	preci_no_width(tab, str, len, digit);
	preci_and_width(tab, str, len, digit);
	free(str);
}

void	ft_print_u(t_print *tab)
{
	int				len;
	unsigned int	digit;
	char			*str;

	digit = va_arg(tab->args, unsigned int);
	str = ft_uitoa(digit);
	len = ft_strlen(str);
	if (digit == 0 && tab->preci == 0 && tab->width == 1)
		len = 0;
	update_tab_diux(tab, len);
	len_width_nopreci(tab, str, len, digit);
	width_len_nopreci(tab, str, len, digit);
	preci_no_width(tab, str, len, digit);
	preci_and_width(tab, str, len, digit);
	free(str);
}
