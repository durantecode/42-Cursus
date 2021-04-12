/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 19:34:32 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/12 20:11:40 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe la cadena de caracteres ’s’ sobre el
descriptor de fichero proporcionado. */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}
