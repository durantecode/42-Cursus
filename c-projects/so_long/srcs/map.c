/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:36:56 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/03 13:37:13 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_draw_floor(t_game *mlx, t_map *m, t_image *img)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	y = 0;
	while (i < m->map_y)
	{
		j = 0;
		x = 0;
		while (j < m->map_x)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, img->f, x, y);
			x += 32;
			j++;
		}
		y += 32;
		i++;
	}
}

void	ft_draw_map(t_game *mlx, t_map *m, t_image *img)
{
	int		i;
	int		j;
	int		x;
	int		y;

	ft_draw_floor(mlx, m, img);
	i = 0;
	y = 0;
	while (i < m->map_y)
	{
		j = 0;
		x = 0;
		while (j < m->map_x)
		{
			if ((ft_strchr("1", m->map[i][j])))
				mlx_put_image_to_window(mlx->ptr, mlx->win, img->w, x, y);
			if ((ft_strchr("C", m->map[i][j])))
				mlx_put_image_to_window(mlx->ptr, mlx->win, img->c, x, y);
			if ((ft_strchr("P", m->map[i][j])))
			{
				mlx_put_image_to_window(mlx->ptr, mlx->win, img->p, x, y);
				mlx->start_x = x;
				mlx->start_y = y;
			}	
			if ((ft_strchr("E", m->map[i][j])))
				mlx_put_image_to_window(mlx->ptr, mlx->win, img->e, x, y);
			x += 32;
			j++;
		}
		y += 32;
		i++;
	}
}

void	ft_check_map_interior(t_map *m)
{
	int		i;
	int		j;
	int		count;

	i = 1;
	j = 1;
	count = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			if (!(ft_strchr("PCE01", m->map[i][j])))
			{
				free(m->map);
				ft_error(5);
			}
			if (m->map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count > 1)
	{
		free(m->map);
		ft_error(6);
	}
}

void	ft_check_map_surrounding(t_map *m)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (j < m->map_x)
	{
		if (m->map[0][j] != '1' || m->map[m->map_y - 1][j] != '1')
		{
			free(m->map);
			ft_error(4);
		}
		j++;
	}
	while (i < m->map_y)
	{
		if (m->map[i][0] != '1' || m->map[i][m->map_x - 1] != '1')
		{
			free(m->map);
			ft_error(4);
		}
		i++;
	}
	ft_check_map_interior(m);
}

void	ft_read_map(int fd, t_map *m, char *argv)
{
	int		ret;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	m->map = malloc(sizeof(char *) * (m->map_y + 1));
	ret = get_next_line(fd, &line);
	while (ret >= 0)
	{
		m->map[i] = ft_strdup(line);
		free(line);
		line = NULL;
		if (ret == 0)
			break ;
		ret = get_next_line(fd, &line);
		i++;
	}
	ft_check_map_surrounding(m);
	close(fd);
}

void	ft_map(int fd, t_game *mlx, t_map *m, char *argv)
{
	char	*line;
	int		ret;

	ret = get_next_line(fd, &line);
	m->map_x = ft_strlen(line);
	m->map_y = 0;
	while (ret >= 0)
	{
		free(line);
		line = NULL;
		m->map_y++;
		if (ret == 0)
			break ;
		ret = get_next_line(fd, &line);
		if (m->map_x != ft_strlen(line))
			ft_error(2);
	}
	if (m->map_x == m->map_y)
		ft_error(3);
	mlx->size.x = m->map_x * 32;
	mlx->size.y = m->map_y * 32;
	close(fd);
	ft_read_map(fd, m, argv);
}
