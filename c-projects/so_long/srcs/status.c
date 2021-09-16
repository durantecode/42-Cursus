/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 02:20:49 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/16 19:04:13 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* This function is always running until we end the program,
it's constantly clearing the window and drawing the map again
with the updated data, plus it calls for some animations */

int	ft_status(t_game *g)
{
	g->time++;
	mlx_clear_window(g->ptr, g->win);
	ft_draw_map(g);
	ft_animation(g);
	if (g->foe.foe_dir == 0)
		ft_move_enemy_left(g);
	else
		ft_move_enemy_right(g);
	mlx_string_put(g->ptr, g->win, 5, g->size_y, 0xFFFFFF, g->move);
	mlx_string_put(g->ptr, g->win, 180, g->size_y, 0xFFFFFF, g->coun);
	return (0);
}

/* This function "animates" some objects in the screen
as the variable time is always counting, I use it to switch
between images and make an "animated" effect */

void	ft_animation(t_game *g)
{
	if (g->time % 20 == 0)
	{
		if (g->img.sprite == g->img.c2)
			g->img.sprite = g->img.c;
		else
			g->img.sprite = g->img.c2;
	}
	if (g->time % 50 == 0)
	{
		if (g->img.sp == g->img.f3)
			g->img.sp = g->img.f;
		else if (g->img.sp == g->img.f2)
			g->img.sp = g->img.f3;
		else
			g->img.sp = g->img.f2;
	}
}
