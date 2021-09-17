/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:14:53 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/12 20:00:09 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// REVISAR

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*ptr;
	size_t	dst_len;
	size_t	src_len;

	ptr = (char *)src;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(ptr);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	while (*ptr && (dst_len + 1) < dstsize)
	{
		dst[dst_len] = *ptr;
		dst_len++;
		ptr++;
	}
	dst[dst_len] = '\0';
	while (*ptr++)
		dst_len++;
	return (dst_len);
}
