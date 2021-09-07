/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 12:40:27 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/07 20:49:22 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Finishes de program, the e variable uses different values
for different messages when quitting */

int	ft_exit(int e, t_game *g)
{
	if (e == 1 || e == 2)
	{
		mlx_destroy_image(g->ptr, g->img.w);
		mlx_destroy_image(g->ptr, g->img.c);
		mlx_destroy_image(g->ptr, g->img.c2);
		mlx_destroy_image(g->ptr, g->img.p);
		mlx_destroy_image(g->ptr, g->img.e);
		mlx_destroy_image(g->ptr, g->img.e2);
		mlx_destroy_image(g->ptr, g->img.f);
		mlx_destroy_window(g->ptr, g->win);
		if (e == 1)
			printf("YOU WON! THANKS FOR PLAYING :)\n");
		if (e == 2)
			printf("YOU QUIT THE GAME WITHOUTH FINISHING :(\n");
	}
	if (g->m.map)
		free(g->m.map);
	else
		g->m.map = NULL;
	exit(0);
	return (0);
}

/* All the errors listed depending on what error was encountered */

int	ft_error(int n, t_game *g)
{
	if (n == 0)
		printf("Error\nWrong argument count\n");
	if (n == 1)
		printf("Error\nCould not open map file, must be a .ber file\n");
	if (n == 2)
		printf("Error\nEvery line of the map must have the same length\n");
	if (n == 3)
		printf("Error\nThe map must be a rectangle\n");
	if (n == 4)
		printf("Error\nMap must be surrounded by walls (1)\n");
	if (n == 5)
		printf("Error\nMap must only contain correct characters (PCE01)\n");
	if (n == 6)
		printf("Error\nThere must be only one player\n");
	if (n == 7)
		printf("Error\nThere must be at least 1 player, 1 exit and 1 collect\n");
	if (n == 8)
		printf("Error\nThere was an error allocating memory\n");
	if (n == 9)
		printf("Error\nThe map is not a .ber file\n");
	ft_exit(3, g);
	return (0);
}
