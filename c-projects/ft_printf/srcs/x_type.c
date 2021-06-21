/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:21:56 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/21 15:30:24 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_x(t_print *tab, int i)
{
	int				len;
	unsigned int	digit;
	char			*str;

	digit = va_arg(tab->args, int);
	str = check_number(digit, i);
	len = ft_strlen(str);
	update_tab_diu(tab, len);
	len_width_nopreci(tab, str, len, digit);
	width_len_nopreci(tab, str, len, digit);
	preci_no_width(tab, str, len, digit);
	preci_and_width(tab, str, len, digit);
	free(str);
}