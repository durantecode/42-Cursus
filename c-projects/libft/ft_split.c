/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 19:23:22 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/15 17:19:54 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns an array
** of strings obtained by splitting ’s’ using the
** character ’c’ as a delimiter. The array must be
** ended by a NULL pointer.
*/

#include "libft.h"

static int	ft_count_string(const char *s1, char c)
{
	int		counter;
	int		i;

	i = 0;
	counter = 0;
	if (!s1)
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] != c)
		{
			counter++;
			while (s1[i] != c && s1[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (counter);
}

static int	ft_count_chars(const char *s1, char c, int i)
{
	int		counter;

	counter = 0;
	if (!s1)
		return (0);
	while (s1[i] != '\0' && s1[i] != c)
	{
		counter++;
		i++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**dst;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	dst = malloc(sizeof(char *) * ft_count_string(s, c) + 1);
	if (!dst)
		return (NULL);
	while (s[i])
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[j] = malloc(sizeof(char) * ft_count_chars(s, c, i) + 1);
		if (dst[j] == NULL)
			return (NULL);
		while (s[i] && s[i] != c)
		{
			dst[j][k] = s[i];
			i++;
			k++;
		}
		dst[j][k] = '\0';
		j++;
	}
	dst[ft_count_string(s, c)] = NULL;
	return (dst);
}

// int		main(void)
// {
// 	char	**dst;
	
// 	dst = ft_split("  tripouille  42  ", ' ');
	
// 	printf("%s\n", dst[0]);
// 	printf("%s\n", dst[1]);
// 	printf("%s\n", dst[2]);
// // 	// printf("%s\n", dst[3]);
// // 	printf("%d\n", ft_count_string("     ", ' '));
// // 	printf("%d\n", ft_count_chars("     ", ' ', 0));
	
// }


// void	ft_print_result(char const *s)
// {
// 	int		len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }

// int		main(void)
// {
// 	char	**tabstr;
// 	int		i;

// 	i = 0;
// 	if (!(tabstr = ft_split("          ", ' ')))
// 		ft_print_result("NULL");
// 	else
// 	{
// 		while (tabstr[i] != NULL)
// 		{
// 			ft_print_result(tabstr[i]);
// 			write(1, "\n", 1);
// 			i++;
// 		}
// 	}
// 	printf("%d\n", tabstr[0] == NULL);
// }