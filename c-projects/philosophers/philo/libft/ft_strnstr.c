/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:08:52 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/13 10:14:33 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[x] != '\0')
	{
		y = 0;
		while (needle[y] == haystack[x + y] && (x + y) < len)
		{
			if (needle[y + 1] == '\0')
				return ((char *)haystack + x);
			y++;
		}
		x++;
	}
	return (NULL);
}
