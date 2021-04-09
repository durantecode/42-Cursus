/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@42student.42madrid.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:02:27 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/09 10:40:22 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	number;
	int					negative;

	number = 0;
	negative = 1;
	while ((*str == ' ') || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -negative;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + *str - 48;
		str++;
		if (number > 9223372036854775807)
		{
			if (negative > 0)
				return (-1);
			else
				return (0);	
		}
	}
	return (number * negative);
}
