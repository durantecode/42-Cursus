/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:36:56 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/01 17:49:44 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		ft_read_map(int fd, t_game *mlx)
{
	char	*line;
	int		ret;

	mlx->map.wall_heigth = 0;
	ret = get_next_line(fd, &line);
	mlx->map.wall_length = ft_strlen(line);
	mlx->size.x = ft_strlen(line) * 64;
	while (ret >= 0)
	{
		free(line);
		line = NULL;
		if (ret == 0)
			break ;
		ret = get_next_line(fd, &line);
		mlx->map.wall_heigth;
	}
	mlx->size.y = mlx->map.wall_heigth * 64;
//	close(fd);
	return (0);
}

int		draw_map(int fd, t_game *mlx)
{
	int		ret;
	char	*line;
	
	ret = get_next_line(fd, &line);
	
}