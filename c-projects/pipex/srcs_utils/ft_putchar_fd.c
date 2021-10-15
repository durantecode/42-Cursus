/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 19:30:54 by ldurante          #+#    #+#             */
/*   Updated: 2021/10/15 11:50:01 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the character ’c’ to the given file
descriptor.*/

#include "../includes/pipex.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
