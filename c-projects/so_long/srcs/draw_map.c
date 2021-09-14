/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:01:58 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/14 12:15:22 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* This function iterates the map and draws the whole window
with the space/floor image, then calls another function for
each position to draw the differente images */

void	ft_draw_map(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	while (g->m.map[i] != NULL)
	{
		j = 0;
		while (g->m.map[i][j] != '\0')
		{
			mlx_put_image_to_window(g->ptr, g->win, g->img.sp, 48 * j, 48 * i);
			ft_put_map_to_window(i, j, g);
			j++;
		}
		i++;
	}
}

/* As the program iterates the previous function, it draws
every image depending on what character it encounters, also
saving some values like the player or the enemy's starting position */

void	ft_put_map_to_window(int i, int j, t_game *g)
{
	if (g->m.map[i][j] == '1')
		mlx_put_image_to_window(g->ptr, g->win, g->img.w, 48 * j, 48 * i);
	else
		mlx_put_image_to_window(g->ptr, g->win, g->img.sp, 48 * j, 48 * i);
	if (g->m.map[i][j] == 'C')
		mlx_put_image_to_window(g->ptr, g->win, g->img.sprite, 48 * j, 48 * i);
	if (g->m.map[i][j] == 'P')
	{
		mlx_put_image_to_window(g->ptr, g->win, g->img.p, 48 * j, 48 * i);
		g->start_x = j;
		g->start_y = i;
	}
	if (g->m.map[i][j] == 'F')
	{
		mlx_put_image_to_window(g->ptr, g->win, g->img.sprite2, 48 * j, 48 * i);
		g->foe.foe_x = j;
		g->foe.foe_y = i;
	}
	if (g->m.map[i][j] == 'E')
	{
		if (g->m.c_count > 0)
			mlx_put_image_to_window(g->ptr, g->win, g->img.e, 48 * j, 48 * i);
		else
			mlx_put_image_to_window(g->ptr, g->win, g->img.e2, 48 * j, 48 * i);
	}
}
