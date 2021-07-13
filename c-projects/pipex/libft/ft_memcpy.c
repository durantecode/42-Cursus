/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:01:04 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/08 18:48:14 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
