/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:12:34 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/03 02:36:46 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_hook(int key, t_game *mlx, t_image *img)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_RIGHT)
	{
		//printf("R");
		//mlx_put_image_to_window(mlx->ptr, mlx->win, img->f, mlx->start_x, mlx->start_y);
		mlx->start_x += 64;
		mlx_clear_window(mlx->ptr, mlx->win);
		
		mlx_put_image_to_window(mlx->ptr, mlx->win, img->p, mlx->start_x, mlx->start_y);
	}
	if (key == KEY_LEFT)
	{
		mlx->size.x -= 64;
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx_put_image_to_window(mlx->ptr, mlx->win, img->p, mlx->size.x, mlx->size.y);
	}
	if (key == KEY_DOWN)
	{
		mlx->size.y += 64;
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx_put_image_to_window(mlx->ptr, mlx->win, img->p, mlx->size.x, mlx->size.y);
	}
	if (key == KEY_UP)
	{
		mlx->size.y -= 64;
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx_put_image_to_window(mlx->ptr, mlx->win, img->p, mlx->size.x, mlx->size.y);
	}
	return (0);
}

int	ft_exit(void)
{
	exit(0);
	return (0);
}

int	ft_spare(void)
{
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	mlx;
	t_image	img;
	t_map	m;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != 3)
			ft_error(1);
		ft_map(fd, &mlx, &m, argv[1]);
		mlx.ptr = mlx_init();
		mlx.win = mlx_new_window(mlx.ptr, mlx.size.x, mlx.size.y, "so_long");
		ft_load_files(&mlx, &img);
		ft_draw_map(&mlx, &m, &img);
		mlx_put_image_to_window(mlx.ptr, mlx.win, img.p, mlx.start_x, mlx.start_y);
		mlx_loop_hook(mlx.ptr, ft_spare, (void *) &mlx);
		mlx_hook(mlx.win, 17, 0, ft_exit, (void *) &mlx);
		mlx_key_hook(mlx.win, ft_key_hook, (void *) &mlx);
		//system("leaks so_long");
		mlx_loop(mlx.ptr);
	}
	else
		ft_error(0);
	return (0);
}
