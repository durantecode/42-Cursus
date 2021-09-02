/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 12:40:27 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/02 19:59:05 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		ft_error(int n)
{
	if (n == 0)
		ft_putstr_fd("Error 0: Wrong argument count\n", 1);
	if (n == 1)
		ft_putstr_fd("Error 1: Could not open map file, please write the path to the .ber map file\n", 1);
	if (n == 2)
		ft_putstr_fd("Error 2: An error ocurred while reading the map, check your map and try again\n", 1);
	if (n == 3)
		ft_putstr_fd("Error 3: The map must be a rectangle\n", 1);
	if (n == 4)
		ft_putstr_fd("Error 4: Map must be surrounded by walls (1)\n", 1);
	if (n == 5)
		ft_putstr_fd("Error 5: Map must only contain correct characters (PCE01)\n", 1);
	if (n == 6)
		ft_putstr_fd("Error 6: There must be only one player\n", 1);
	if (n == 7)
		ft_putstr_fd("Error 7:", 1);
	exit(0);
	return (0);
}