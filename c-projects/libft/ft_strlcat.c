/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:14:53 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/08 20:05:32 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// REVISAR

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	offset;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	offset = dst_len;
	if (src_len == 0 && dstsize == 0)
		return (0);
	else if (offset > dstsize - 1)
		return (src_len + dstsize);
	while ((*src != '\0') && (offset < dstsize - 1) && (dstsize != 0))
	{
		*(dst + offset) = *src;
		offset++;
		src++;
	}
	*(dst + offset) = '\0';
	return (dst_len + src_len);
}
