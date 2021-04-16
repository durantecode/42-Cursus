/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 19:23:22 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/16 12:52:51 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns an array
** of strings obtained by splitting ’s’ using the
** character ’c’ as a delimiter. The array must be
** ended by a NULL pointer.
*/

#include "libft.h"

static int	ft_count_string(const char *s, char c)
{
	int		counter;
	int		i;

	i = 0;
	counter = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (counter);
}

static int	ft_count_chars(const char *s, char c, int i)
{
	int		counter;

	counter = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != c)
	{
		counter++;
		i++;
	}
	return (counter);
}

static char	**ft_write_string(char const *s, char **dst, char c, int numstr)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i] && j < numstr)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[j] = malloc(sizeof(char) * ft_count_chars(s, c, i) + 1);
		if (dst[j] == NULL)
			return (NULL);
		while (s[i] && s[i] != c)
			dst[j][k++] = s[i++];
		dst[j][k] = '\0';
		j++;
	}
	dst[numstr] = NULL;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		numstr;

	if (!s)
		return (NULL);
	numstr = ft_count_string(s, c);
	dst = malloc(sizeof(char *) * (numstr + 1));
	if (!dst)
		return (NULL);
	return (ft_write_string(s, dst, c, numstr));
}
