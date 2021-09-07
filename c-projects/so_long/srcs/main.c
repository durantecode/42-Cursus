/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:12:34 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/07 02:05:45 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_exit(void)
{
	exit(0);
	return (0);
}

int	ft_key_hook(int key, t_game *g)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_RIGHT)
	{
		if (g->m.map[g->start_y][g->start_x + 1] == '1')
			return (0);
		// if (g->m.map[g->start_y][g->start_x + 1] == 'C')
		// 	g->c_picked++;
		if (g->m.map[g->start_y][g->start_x + 1] == 'E')
		{
			if (g->c_count > 0)
				return (0);
			if (g->c_count == 0)
				exit(0);
		}
		g->m.map[g->start_y][g->start_x] = '0';
		g->m.map[g->start_y][g->start_x + 1] = 'P';
	}
	if (key == KEY_LEFT)
	{
		if (g->m.map[g->start_y][g->start_x - 1] == '1')
			return (0);
		// if (g->m.map[g->start_y][g->start_x - 1] == 'C')
		// 	g->c_picked++;
		if (g->m.map[g->start_y][g->start_x - 1] == 'E')
		{
			if (g->c_count > 0)
				return (0);
			if (g->c_count == 0)
				exit(0);
		}
		g->m.map[g->start_y][g->start_x] = '0';
		g->m.map[g->start_y][g->start_x - 1] = 'P';
	}
	if (key == KEY_DOWN)
	{
		if (g->m.map[g->start_y + 1][g->start_x] == '1')
			return (0);
		// if (g->m.map[g->start_y + 1][g->start_x] == 'C')
		// 	g->c_picked++;
		if (g->m.map[g->start_y + 1][g->start_x] == 'E')
		{
			if (g->c_count > 0)
				return (0);
			if (g->c_count == 0)
				exit(0);
		}
		g->m.map[g->start_y][g->start_x] = '0';
		g->m.map[g->start_y + 1][g->start_x] = 'P';
	}
	if (key == KEY_UP)
	{
		if (g->m.map[g->start_y - 1][g->start_x] == '1')
			return (0);
		// if (g->m.map[g->start_y - 1][g->start_x] == 'C')
		// 	g->c_picked++;
		if (g->m.map[g->start_y - 1][g->start_x] == 'E')
		{
			if (g->c_count > 0)
				return (0);
			if (g->c_count == 0)
				exit(0);
		}
		g->m.map[g->start_y][g->start_x] = '0';
		g->m.map[g->start_y - 1][g->start_x] = 'P';
	}
	// printf("%d", g->c_count);
	return (0);
}

int	ft_status(t_game *g)
{
	g->frames++;
//	mlx_clear_window(g->ptr, g->win);
	ft_draw_map(g);
	return (0);
}

void	init_values(t_game *g)
{
	g->start_x = 0;
	g->start_y = 0;
	g->size_x = 0;
	g->size_y = 0;
	g->c_count = 0;
	g->frames = 0;
	g->m.map_x = 0;
	g->m.map_y = 0;
}

int	main(int argc, char **argv)
{
	t_game	g;
	int		fd;

	if (argc == 2)
	{
		init_values(&g);
		fd = open(argv[1], O_RDONLY);
		if (fd != 3)
			ft_error(1);
		ft_map(fd, argv[1], &g);
		g.ptr = mlx_init();
		g.win = mlx_new_window(g.ptr, g.size_x, g.size_y, "so_long");
		ft_load_files(&g);
		mlx_loop_hook(g.ptr, ft_status, (void *) &g);
		mlx_hook(g.win, 17, 0, ft_exit, (void *) &g);
		mlx_key_hook(g.win, ft_key_hook, (void *) &g);
		// system("leaks so_long");
		mlx_loop(g.ptr);
	}
	else
		ft_error(0);
	return (0);
}
