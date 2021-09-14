/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 12:40:27 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/14 16:05:07 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* All the errors listed depending on what error was encountered,
then calls the exit function */

int	ft_error(int n, t_game *g)
{
	if (n == 0)
		printf("Error\nWrong argument count\n");
	if (n == 1)
		printf("Error\nCould not open map file\n");
	if (n == 2)
		printf("Error\nEvery line of the map must have the same length\n");
	if (n == 3)
		printf("Error\nThe map must be a rectangle\n");
	if (n == 4)
		printf("Error\nMap must be surrounded by walls (1)\n");
	if (n == 5)
		printf("Error\nMap must only contain correct characters (PCE01)\n");
	if (n == 6)
		printf("Error\nThere must be only one player & one exit\n");
	if (n == 7)
		printf("Error\nThere must be at least 1 player, 1 exit and 1 collect\n");
	if (n == 8)
		printf("Error\nThere was an error allocating memory\n");
	if (n == 9)
		printf("Error\nThe map is not a .ber file\n");
	ft_exit(0, g);
	return (0);
}

/* Auxiliary function just called when you press ESC or 
close the window with the red button*/

int	ft_close(t_game *g)
{
	ft_exit(2, g);
	return (0);
}

/* Small function to free the 2D map array */

void	free_map(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->m.map_y)
	{
		free(g->m.map[i]);
		i++;
	}
	free(g->m.map[i]);
	free(g->m.map);
}

/* Destroys every image, clears the window and then
destroys it */

void	ft_destroy(t_game *g)
{
	mlx_destroy_image(g->ptr, g->img.w);
	mlx_destroy_image(g->ptr, g->img.f);
	mlx_destroy_image(g->ptr, g->img.f2);
	mlx_destroy_image(g->ptr, g->img.f3);
	mlx_destroy_image(g->ptr, g->img.c);
	mlx_destroy_image(g->ptr, g->img.c2);
	mlx_destroy_image(g->ptr, g->img.e);
	mlx_destroy_image(g->ptr, g->img.e2);
	mlx_destroy_image(g->ptr, g->img.foe);
	mlx_destroy_image(g->ptr, g->img.foe2);
	mlx_destroy_image(g->ptr, g->img.p);
	mlx_clear_window(g->ptr, g->win);
	mlx_destroy_window(g->ptr, g->win);
}

/* Finishes the program, the e variable uses different values
for different messages when quitting and freeing all the memory
that was allocated */

int	ft_exit(int e, t_game *g)
{
	if (e == 1)
		printf("%sYOU WON! :)\nMOVEMENTS: %d\n%s", G, g->key_count + 1, NC);
	if (e == 2)
		printf("%sYOU QUIT THE GAME WITHOUT FINISHING! :(\n%s", Y, NC);
	if (e == 3)
		printf("%sYOU LOSE! NO NUTELLA FOR YOU :(\n%s", R, NC);
	if (g->m.map)
		free_map(g);
	if (g->move)
		free(g->move);
	if (g->ptr)
		ft_destroy(g);
	exit(0);
	return (0);
}
