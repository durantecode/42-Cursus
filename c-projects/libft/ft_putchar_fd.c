/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 19:30:54 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/12 20:14:39 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Escribe el carácter ’c’ sobre el descriptor de
fichero proporcionado.*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
