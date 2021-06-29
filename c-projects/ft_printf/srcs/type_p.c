/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:52:30 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/29 22:30:24 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*check_number(unsigned long nb, int i)
{
	long	n;

	n = (long)nb;
	if ((n >= -2147483648 && nb <= 4294967295))
	{
		n = (unsigned int) n;
		return (ft_itoa_base(n, 16, i));
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
	if (digit == 0 && tab->point && !tab->p_star)
		aux = ft_strdup("");
	else
		aux = check_number(digit, 0);
	str = ft_strjoin("0x", aux);
	len = ft_strlen(str);
	if (tab->width >= len)
		basic_width(tab, str, len);
	else
		tab->length += write(1, str, len);
	free(str);
	free(aux);
}
