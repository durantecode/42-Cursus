/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 12:40:27 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/14 03:09:56 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Checks if the string passed as argument is a ".ber" file,
basically checks the last 4 chars of the string */

void	check_file_extension(char *argv, t_game *g)
{
	int		len;
	char	*ext;
	char	*aux;
	int		i;

	len = ft_strlen(argv);
	ext = ft_strdup(".ber");
	aux = ft_substr(argv, len - 4, len);
	i = 0;
	len = 0;
	while (i < 4)
	{
		if (ext[i] == aux[i])
			len++;
		i++;
	}
	if (len != 4)
		ft_error(9, g);
	free(ext);
	free(aux);
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

/* Finishes de program, the e variable uses different values
for different messages when quitting and freeing all the memory
that was allocated */

int	ft_exit(int e, t_game *g)
{
	if (e == 1)
		printf("YOU WON! :)\nNUMBER OF MOVEMENTS: %d\n", g->key_count + 1);
	if (e == 2)
		printf("YOU QUIT THE GAME WITHOUTH PLAYING! :(\n");
	if (e == 3)
		printf("YOU LOSE! NO NUTELLA FOR YOU :(\n");
	if (g->m.map)
		free_map(g);
	if (g->move)
		free(g->move);
//	system("leaks so_long");
	exit(0);
	return (0);
}

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
