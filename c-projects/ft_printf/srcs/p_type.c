/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:52:30 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/17 18:55:32 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_numlen_base(unsigned long n, int base)
{
	int		i;

	i = 0;
	if (n == 0)
	{
		i += 1;
		return (i);
	}
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

char	*ft_itoa_base(unsigned int nb, unsigned int base)
{
	char	*ret;
	char	*numbers;
	int		size;

	numbers = ft_strdup("0123456789abcdef");
	ret = NULL;
	size = ft_numlen_base(nb, base);
	if (!(ret = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ret[size--] = '\0';
	while (size >= 0)
	{
		ret[size--] = numbers[nb % base];
		nb /= base;
	}
	free(numbers);
	return (ret);
}

void	ft_print_pointer(t_print *tab)
{
	int digit;
	char *str;
	
	digit = (unsigned int) va_arg(tab->args, char *);
	str = ft_itoa_base(digit, 16);
	if (!ft_isascii(digit) && digit > 0)
		tab->length += write(1, "0x10", 4);
	else
		tab->length += write(1, "0x", 2);
	tab->length += write(1, str, ft_strlen(str));
	free(str);
}