/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:01:41 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/21 12:16:19 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_uint_len(unsigned long int n)
{
	int	len;

	len = 0;
	if (n < 10)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned long int n)
{
	char	*str;
	int		len;

	len = ft_uint_len(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (len == 0)
		return (0);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = n % 10 + '0';
		len--;
		n = n / 10;
	}
	return (str);
}
