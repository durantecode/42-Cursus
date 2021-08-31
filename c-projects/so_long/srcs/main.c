/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:12:34 by ldurante          #+#    #+#             */
/*   Updated: 2021/08/31 02:58:15 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		img;
	int		txt;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "TEST");
//	img = mlx_pixel_put(mlx, mlx_win, 200, 200, 0x00FF0000);

	char	*line;
	int		fd;
	int		ret;
	int		y = 200;

	fd = open("text.txt", O_RDONLY);
	ret = get_next_line(fd, &line);
	while (ret >= 0)
	{
		txt = mlx_string_put(mlx, mlx_win, 200, y, 0x00FFFF00, line);
		free(line);
		line = NULL;
		if (ret == 0)
			break ;
		ret = get_next_line(fd, &line);
		y += 20;
	}
	free(line);
	close(fd);
//	txt = mlx_string_put(mlx, mlx_win, 200, 300, 0x00FFFF00, "PRUEBA");
	mlx_loop(mlx);
}
