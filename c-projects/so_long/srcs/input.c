/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:16:32 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/13 19:10:01 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_up(t_game *g)
{
	if (g->m.map[g->start_y - 1][g->start_x] == '1')
		return (0);
	if (g->m.map[g->start_y - 1][g->start_x] == 'C')
		g->m.c_count--;
	if (g->m.map[g->start_y - 1][g->start_x] == 'E')
	{
		if (g->m.c_count > 0)
			return (0);
		if (g->m.c_count == 0)
			ft_exit(1, g);
	}
	g->m.map[g->start_y][g->start_x] = '0';
	g->m.map[g->start_y - 1][g->start_x] = 'P';
	g->key_count++;
	return (0);
}

int	move_down(t_game *g)
{
	if (g->m.map[g->start_y + 1][g->start_x] == '1')
		return (0);
	if (g->m.map[g->start_y + 1][g->start_x] == 'C')
		g->m.c_count--;
	if (g->m.map[g->start_y + 1][g->start_x] == 'E')
	{
		if (g->m.c_count > 0)
			return (0);
		if (g->m.c_count == 0)
			ft_exit(1, g);
	}
	g->m.map[g->start_y][g->start_x] = '0';
	g->m.map[g->start_y + 1][g->start_x] = 'P';
	g->key_count++;
	return (0);
}

int	move_left(t_game *g)
{
	if (g->m.map[g->start_y][g->start_x - 1] == '1')
		return (0);
	if (g->m.map[g->start_y][g->start_x - 1] == 'C')
		g->m.c_count--;
	if (g->m.map[g->start_y][g->start_x - 1] == 'E')
	{
		if (g->m.c_count > 0)
			return (0);
		if (g->m.c_count == 0)
			ft_exit(1, g);
	}
	g->m.map[g->start_y][g->start_x] = '0';
	g->m.map[g->start_y][g->start_x - 1] = 'P';
	g->key_count++;
	return (0);
}

int	move_right(t_game *g)
{
	if (g->m.map[g->start_y][g->start_x + 1] == '1')
		return (0);
	if (g->m.map[g->start_y][g->start_x + 1] == 'C')
		g->m.c_count--;
	if (g->m.map[g->start_y][g->start_x + 1] == 'E')
	{
		if (g->m.c_count > 0)
			return (0);
		if (g->m.c_count == 0)
			ft_exit(1, g);
	}
	g->m.map[g->start_y][g->start_x] = '0';
	g->m.map[g->start_y][g->start_x + 1] = 'P';
	g->key_count++;
	return (0);
}

int	ft_key_input(int key, t_game *g)
{
	if (key == KEY_ESC || key == KEY_RIGHT || key == KEY_LEFT
		|| key == KEY_UP || key == KEY_DOWN)
	{		
		if (key == KEY_ESC)
		{
			ft_close(g);
			return (0);
		}
		if (key == KEY_RIGHT)
			move_right(g);
		if (key == KEY_LEFT)
			move_left(g);
		if (key == KEY_DOWN)
			move_down(g);
		if (key == KEY_UP)
			move_up(g);
		free(g->coun);
		g->coun = ft_itoa(g->key_count);
		return (1);
	}
	else
		return (0);
}
