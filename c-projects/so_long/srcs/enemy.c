/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 01:57:33 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/14 02:17:27 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Calls the enemy image depending if it's looking right or left
then checks the next tile and if it's empty, it moves, if it's a wall,
a collectible or the exit, it changes direction, and if it's the player
it finishes the game */

void	ft_move_enemy_right(t_game *g)
{
	g->img.sprite2 = g->img.foe2;
	if (g->time % 22 == 0)
	{
		if (g->m.map[g->foe.foe_y][g->foe.foe_x + 1] == '1')
			g->foe.foe_dir = 0;
		if (g->m.map[g->foe.foe_y][g->foe.foe_x + 1] == 'C')
			g->foe.foe_dir = 0;
		if (g->m.map[g->foe.foe_y][g->foe.foe_x + 1] == 'E')
			g->foe.foe_dir = 0;
		if (g->m.map[g->foe.foe_y][g->foe.foe_x + 1] == 'P')
		{
			g->m.map[g->foe.foe_y][g->foe.foe_x] = '0';
			g->m.map[g->foe.foe_y][g->foe.foe_x + 1] = 'F';
			ft_exit(3, g);
		}
		if (g->m.map[g->foe.foe_y][g->foe.foe_x + 1] == '0'
			&& g->foe.foe_dir == 1)
		{
			g->m.map[g->foe.foe_y][g->foe.foe_x] = '0';
			g->m.map[g->foe.foe_y][g->foe.foe_x + 1] = 'F';
		}
	}
}

void	ft_move_enemy_left(t_game *g)
{
	g->img.sprite2 = g->img.foe;
	if (g->time % 22 == 0)
	{
		if (g->m.map[g->foe.foe_y][g->foe.foe_x - 1] == '1')
			g->foe.foe_dir = 1;
		if (g->m.map[g->foe.foe_y][g->foe.foe_x - 1] == 'C')
			g->foe.foe_dir = 1;
		if (g->m.map[g->foe.foe_y][g->foe.foe_x - 1] == 'E')
			g->foe.foe_dir = 1;
		if (g->m.map[g->foe.foe_y][g->foe.foe_x - 1] == 'P')
		{
			g->m.map[g->foe.foe_y][g->foe.foe_x] = '0';
			g->m.map[g->foe.foe_y][g->foe.foe_x - 1] = 'F';
			ft_exit(3, g);
		}
		if (g->m.map[g->foe.foe_y][g->foe.foe_x - 1] == '0'
			&& g->foe.foe_dir == 0)
		{
			g->m.map[g->foe.foe_y][g->foe.foe_x] = '0';
			g->m.map[g->foe.foe_y][g->foe.foe_x - 1] = 'F';
		}
	}
}
