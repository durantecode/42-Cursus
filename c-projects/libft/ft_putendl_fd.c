/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 19:37:39 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/12 20:06:13 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe la cadena de caracteres ’s’ sobre el
descriptor de fichero proporcionado, seguida de
un salto de línea. */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
