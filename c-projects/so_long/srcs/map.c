/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:36:56 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/07 01:53:53 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_draw_floor(t_game *g)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	y = 0;
	while (i < g->m.map_y)
	{
		j = 0;
		x = 0;
		while (j < g->m.map_x)
		{
			mlx_put_image_to_window(g->ptr, g->win, g->img.f, x, y);
			x += 32;
			j++;
		}
		y += 32;
		i++;
	}
}

void	ft_draw_map(t_game *g)
{
	int		i;
	int		j;
	int		x;
	int		y;
	g->c_count = 0;

	ft_draw_floor(g);
	i = 0;
	y = 0;
	while (i < g->m.map_y)
	{
		j = 0;
		x = 0;
		while (j < g->m.map_x)
		{
			if ((ft_strchr("1", g->m.map[i][j])))
				mlx_put_image_to_window(g->ptr, g->win, g->img.w, x, y);
			if ((ft_strchr("C", g->m.map[i][j])))
			{
				mlx_put_image_to_window(g->ptr, g->win, g->img.c, x, y);
				g->c_count++;
			}
			if ((ft_strchr("P", g->m.map[i][j])))
			{
				mlx_put_image_to_window(g->ptr, g->win, g->img.p, x, y);
				g->start_x = j;
				g->start_y = i;
			}	
			if ((ft_strchr("E", g->m.map[i][j])))
			{
				if (g->c_count > 0)
					mlx_put_image_to_window(g->ptr, g->win, g->img.e, x, y);
				else
					mlx_put_image_to_window(g->ptr, g->win, g->img.e2, x, y);
			}
			x += 32;
			j++;
		}
		y += 32;
		i++;
	}
	// printf("%d", g->c_count);
}

void	ft_check_map_interior(t_game *g)
{
	int		i;
	int		j;
	int		count;

	i = 1;
	j = 1;
	count = 0;
	while (i < g->m.map_y)
	{
		j = 0;
		while (j < g->m.map_x)
		{
			if (!(ft_strchr("PCE01", g->m.map[i][j])))
			{
				free(g->m.map);
				ft_error(5);
			}
			if (g->m.map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count > 1)
	{
		free(g->m.map);
		ft_error(6);
	}
}

void	ft_check_map_surrounding(t_game *g)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (j < g->m.map_x)
	{
		if (g->m.map[0][j] != '1' || g->m.map[g->m.map_y - 1][j] != '1')
		{
			free(g->m.map);
			ft_error(4);
		}
		j++;
	}
	while (i < g->m.map_y)
	{
		if (g->m.map[i][0] != '1' || g->m.map[i][g->m.map_x - 1] != '1')
		{
			free(g->m.map);
			ft_error(4);
		}
		i++;
	}
	ft_check_map_interior(g);
}

void	ft_read_map(int fd, char *argv, t_game *g)
{
	int		ret;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	g->m.map = malloc(sizeof(char *) * (g->m.map_y + 1));
	ret = get_next_line(fd, &line);
	while (ret >= 0)
	{
		g->m.map[i] = ft_strdup(line);
		free(line);
		line = NULL;
		if (ret == 0)
			break ;
		ret = get_next_line(fd, &line);
		i++;
	}
	ft_check_map_surrounding(g);
	close(fd);
}

void	ft_map(int fd, char *argv, t_game *g)
{
	char	*line;
	int		ret;

	ret = get_next_line(fd, &line);
	g->m.map_x = ft_strlen(line);
	g->m.map_y = 0;
	while (ret >= 0)
	{
		free(line);
		line = NULL;
		g->m.map_y++;
		if (ret == 0)
			break ;
		ret = get_next_line(fd, &line);
		if (g->m.map_x != ft_strlen(line))
			ft_error(2);
	}
	if (g->m.map_x == g->m.map_y)
		ft_error(3);
	g->size_x = g->m.map_x * 32;
	g->size_y = g->m.map_y * 32;
	close(fd);
	ft_read_map(fd, argv, g);
}
