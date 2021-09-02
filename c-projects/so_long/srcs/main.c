/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:12:34 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/02 23:07:23 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		ft_key_hook(int key, t_game *mlx)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_RIGHT)
	{
		mlx->size.x += 64;
		mlx_clear_window(mlx->mlx_ptr, mlx->window);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->wall, mlx->size.x, mlx->size.y);
	}
	if (key == KEY_LEFT)
	{
		mlx->size.x -= 64;
		mlx_clear_window(mlx->mlx_ptr, mlx->window);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->wall, mlx->size.x, mlx->size.y);
	}
	if (key == KEY_DOWN)
	{
		mlx->size.y += 64;
		mlx_clear_window(mlx->mlx_ptr, mlx->window);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->wall, mlx->size.x, mlx->size.y);
	}
	if (key == KEY_UP)
	{
		mlx->size.y -= 64;
		mlx_clear_window(mlx->mlx_ptr, mlx->window);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->wall, mlx->size.x, mlx->size.y);
	}
	return (0);
}

int		ft_exit(void)
{
	exit(0);
	return (0);
}

int		ft_spare(void)
{
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	mlx;
	int		bpp;
	int		line;
	int		endian;
	int		fd;
	t_map	m;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != 3)
			ft_error(1);
		ft_map(fd, &mlx, &m, argv[1]);
		mlx.mlx_ptr = mlx_init();
		mlx.window = mlx_new_window(mlx.mlx_ptr, mlx.size.x, mlx.size.y, "so_long");
		mlx.wall = mlx_xpm_file_to_image(mlx.mlx_ptr, "xpm/wall2.xpm", &mlx.size.x, &mlx.size.y);
		mlx.pixels = mlx_get_data_addr(mlx.wall, &bpp, &line, &endian);
		mlx.collect = mlx_xpm_file_to_image(mlx.mlx_ptr, "xpm/sandwich.xpm", &mlx.size.x, &mlx.size.y);
		mlx.pixels2 = mlx_get_data_addr(mlx.collect, &bpp, &line, &endian);
		mlx.player = mlx_xpm_file_to_image(mlx.mlx_ptr, "xpm/pavon.xpm", &mlx.size.x, &mlx.size.y);
		mlx.pixels3 = mlx_get_data_addr(mlx.collect, &bpp, &line, &endian);
		ft_draw_map(&mlx, &m);
	//	mlx_put_image_to_window(mlx.mlx_ptr, mlx.window, mlx.image, 0, 0);
		mlx_loop_hook(mlx.mlx_ptr, ft_spare, (void *) &mlx);
		mlx_hook(mlx.window, 17, 0, ft_exit, (void *) &mlx);
		mlx_key_hook(mlx.window, ft_key_hook, (void *) &mlx);
		//system("leaks so_long");
		mlx_loop(mlx.mlx_ptr);
	}
	else
		ft_error(0);
	return (0);
}
