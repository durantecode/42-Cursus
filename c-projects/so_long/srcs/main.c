/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:12:34 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/16 12:50:45 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Initialize values of the struct */

void	init_values(t_game *g)
{
	g->ptr = NULL;
	g->start_x = 0;
	g->start_y = 0;
	g->size_x = 0;
	g->size_y = 0;
	g->time = 0;
	g->key_count = 0;
	g->foe.foe_dir = 0;
	g->coun = ft_strdup("0");
	g->move = ft_strdup("TOTAL MOVEMENTS: ");
	g->m.map = NULL;
	g->m.map_x = 0;
	g->m.map_y = 0;
	g->m.c_count = 0;
	g->m.e_count = 0;
	g->m.p_count = 0;
}

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

int	main(int argc, char **argv)
{
	t_game	g;
	int		fd;

	init_values(&g);
	if (argc == 2)
	{
		check_file_extension(argv[1], &g);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_error(1, &g);
		ft_map(fd, argv[1], &g);
		g.ptr = mlx_init();
		g.win = mlx_new_window(g.ptr, g.size_x, g.size_y + 23, "so_long");
		ft_load_files(&g);
		mlx_loop_hook(g.ptr, ft_status, (void *) &g);
		mlx_hook(g.win, 17, 0, ft_close, (void *) &g);
		mlx_key_hook(g.win, ft_key_input, (void *) &g);
		mlx_loop(g.ptr);
	}
	else
		ft_error(0, &g);
	return (0);
}
