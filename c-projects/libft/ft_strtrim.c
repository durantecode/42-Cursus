/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:59:39 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/12 19:20:24 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Reserva memoria (con malloc(3)) y devuelve la
** cadena de caracteres que es una copia de ’s1’, sin
** los caracteres indicados en el ’set’ al principio y
** al final de la cadena de caracteres.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	if (!len)
		return ("");
	return (ft_substr(s1, 0, len + 1));
}
