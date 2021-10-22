/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:31:10 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/08 15:51:19 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *) s1;
	b = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (*a == *b && n > 0)
	{
		a++;
		b++;
		n--;
		if (n == 0)
			return (0);
	}
	if (*a != *b)
		return (*a - *b);
	return (0);
}
