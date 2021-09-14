/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:36:56 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/14 16:12:40 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Reads the map the first time using GNL to get the full size
And checks for errors if there's a line shorter than other or
the map is a square */

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
			ft_error(2, g);
	}
	if (g->m.map_x == g->m.map_y)
		ft_error(3, g);
	g->size_x = g->m.map_x * 48;
	g->size_y = g->m.map_y * 48;
	close(fd);
	ft_read_map(fd, argv, g);
}

/* Reads the map a second time using GNL again, but this time
copying each line to a 2 dimension array called "map" */

void	ft_read_map(int fd, char *argv, t_game *g)
{
	int		ret;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	g->m.map = malloc(sizeof(char *) * (g->m.map_y + 1));
	if (!g->m.map)
		ft_error(8, g);
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
	g->m.map[++i] = NULL;
	ft_check_map_surrounding(g);
	close(fd);
}

/* Iterates the map array on the top/bottom line and the first
and last character of each line. They must be '1'. If not calls 
the error function and quits the program */

void	ft_check_map_surrounding(t_game *g)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (j < g->m.map_x)
	{
		if (g->m.map[0][j] != '1' || g->m.map[g->m.map_y - 1][j] != '1')
			ft_error(4, g);
		j++;
	}
	while (i < g->m.map_y)
	{
		if (g->m.map[i][0] != '1' || g->m.map[i][g->m.map_x - 1] != '1')
			ft_error(4, g);
		i++;
	}
	ft_check_map_interior(i, j, g);
}

/* Iterates again the map array checking the interior part
counting each Wall, Collectible and Player, that we will use
later. Also checks for errors on the number of players... etc */

void	ft_check_map_interior(int i, int j, t_game *g)
{
	i = 1;
	j = 1;
	while (i < g->m.map_y)
	{
		j = 0;
		while (j < g->m.map_x)
		{
			if (!(ft_strchr("PCE01F", g->m.map[i][j])))
				ft_error(5, g);
			if (g->m.map[i][j] == 'E')
				g->m.e_count++;
			if (g->m.map[i][j] == 'P')
				g->m.p_count++;
			if (g->m.map[i][j] == 'C')
				g->m.c_count++;
			j++;
		}
		i++;
	}
	if (g->m.e_count < 1 || g->m.p_count < 1 || g->m.c_count < 1)
		ft_error(7, g);
	if (g->m.p_count > 1 || g->m.e_count > 1)
		ft_error(6, g);
}
