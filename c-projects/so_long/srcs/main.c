/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:12:34 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/01 00:57:50 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		close_window(int key, int *param)
{
	if (key == 53)
		exit(0);
	return (0);
}

// t_image	ft_new_sprite(void *mlx, char *path)
// {
// 	t_image	img;
	
// 	img.pointer = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
// 	img.pixels  = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
// 	return (img);
// }

int	main(void)
{
	t_game	mlx;
	int		bpp;
	int		line;
	int		endian;

	mlx.mlx_ptr = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx_ptr, 800, 800, "TEST");
	mlx.image = mlx_xpm_file_to_image(mlx.mlx_ptr, "xpm/robot2.xpm", &mlx.size.x, &mlx.size.y);
	mlx.pixels = mlx_get_data_addr(mlx.image, &bpp, &line, &endian);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.window, mlx.image, 100, 100);
	mlx_hook(mlx.window, 2, 0, close_window, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
