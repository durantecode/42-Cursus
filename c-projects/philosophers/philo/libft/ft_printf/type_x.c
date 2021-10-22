/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:21:56 by ldurante          #+#    #+#             */
/*   Updated: 2021/10/01 00:53:30 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_x(t_print *tab, int i)
{
	int				len;
	unsigned int	digit;
	char			*str;

	digit = va_arg(tab->args, int);
	str = check_number(digit, i);
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
