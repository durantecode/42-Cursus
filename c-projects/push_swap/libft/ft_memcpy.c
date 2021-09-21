/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:01:04 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/21 22:08:05 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The memcpy() function copies n bytes from 
memory area src to memory area dest.
The memory areas must not overlap. */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*a;
	char	*b;

	if (dst == NULL && src == NULL)
		return (NULL);
	a = (char *)src;
	b = (char *)dst;
	while (n--)
		*b++ = *a++;
	return (dst);
}
