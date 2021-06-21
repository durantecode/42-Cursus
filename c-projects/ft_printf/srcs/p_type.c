/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:52:30 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/21 16:04:43 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*check_number(unsigned long nb, int i)
{
	if ((nb >= -2147483648 && nb <= 2147483647)
		|| (nb >= 0 && nb <= 4294967295))
	{
		nb = (unsigned int) nb;
		return (ft_itoa_base(nb, 16, i));
	}
	return (ft_uitoa_base(nb, 16, i));
}

void	ft_print_pointer(t_print *tab)
{
	long	digit;
	char	*str;
	char	*aux;
	int		len;

	digit = (long) va_arg(tab->args, void *);
	aux = check_number(digit, 0);
	if (!ft_isascii(digit) && digit > 0 && digit < 2147483647)
		str = ft_strjoin("0x10", aux);
	else
		str = ft_strjoin("0x", aux);
	len = ft_strlen(str);
	if (tab->width >= len)
		basic_width(tab, str, len);
	else
		tab->length += write(1, str, len);
	free(str);
	free(aux);
}
