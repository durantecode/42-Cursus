/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_hex_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:01:00 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/21 15:38:42 by ldurante         ###   ########.fr       */
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

char	*ft_itoa_base(unsigned int nb, unsigned int base, int i)
{
	char	*ret;
	char	*numbers;
	int		size;

	if (i == 0)
		numbers = ft_strdup("0123456789abcdef");
	else
		numbers = ft_strdup("0123456789ABCDEF");
	ret = NULL;
	size = ft_numlen_base(nb, base);
	ret = (char *)malloc(sizeof(char) * size + 1);
	if (!ret)
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

char	*ft_uitoa_base(unsigned long nb, unsigned int base, int i)
{
	char	*ret;
	char	*numbers;
	int		size;

	if (i == 0)
		numbers = ft_strdup("0123456789abcdef");
	else
		numbers = ft_strdup("0123456789ABCDEF");
	ret = NULL;
	size = ft_numlen_base(nb, base);
	ret = (char *)malloc(sizeof(char) * size + 1);
	if (!ret)
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
