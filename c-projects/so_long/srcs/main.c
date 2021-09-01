/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:12:34 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/01 17:45:59 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		ft_key_hook(int key, t_game *mlx)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_RIGHT)
	{
		mlx->size.x += 10;
		mlx_clear_window(mlx->mlx_ptr, mlx->window);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->image, mlx->size.x, mlx->size.y);
	}
	if (key == KEY_LEFT)
	{
		mlx->size.x -= 10;
		mlx_clear_window(mlx->mlx_ptr, mlx->window);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->image, mlx->size.x, mlx->size.y);
	}
	if (key == KEY_DOWN)
	{
		mlx->size.y += 10;
		mlx_clear_window(mlx->mlx_ptr, mlx->window);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->image, mlx->size.x, mlx->size.y);
	}
	if (key == KEY_UP)
	{
		mlx->size.y -= 10;
		mlx_clear_window(mlx->mlx_ptr, mlx->window);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->image, mlx->size.x, mlx->size.y);
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

	char	*map;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ft_read_map(fd, &mlx);
		mlx.mlx_ptr = mlx_init();
		mlx.window = mlx_new_window(mlx.mlx_ptr, mlx.size.x, mlx.size.y, "so_long");
		draw_map(fd, &mlx);
		mlx.image = mlx_xpm_file_to_image(mlx.mlx_ptr, "xpm/wall.xpm", &mlx.size.x, &mlx.size.y);
		mlx.pixels = mlx_get_data_addr(mlx.image, &bpp, &line, &endian);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.window, mlx.image, 0, 0);
		mlx_loop_hook(mlx.mlx_ptr, ft_spare, (void *) &mlx);
		mlx_hook(mlx.window, 17, 0, ft_exit, (void *) &mlx);
		mlx_key_hook(mlx.window, ft_key_hook, (void *) &mlx);
		// system("leaks so_long");
		mlx_loop(mlx.mlx_ptr);
	}
	return (0);
}
