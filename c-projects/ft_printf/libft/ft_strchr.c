/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:46:30 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/08 11:37:36 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		x;
	int		len;

	x = 0;
	len = ft_strlen(s);
	while (x < len + 1)
	{
		if (s[x] == (char)c)
			return ((char *)s + x);
		x++;
	}
	return (NULL);
}
