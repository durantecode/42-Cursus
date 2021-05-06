/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:17:25 by ldurante          #+#    #+#             */
/*   Updated: 2021/05/06 11:51:45 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	else
	{
		while (s1[i] != '\0')
		{
			ptr[i] = s1[i];
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	else
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		str = malloc(len + 1);
		if (!str)
			return (NULL);
		i = 0;
		while (++i - 1 < len)
			*(str + i - 1) = *(s + start + i - 1);
		*(str + i - 1) = '\0';
		return (str);
	}
}
