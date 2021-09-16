/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:52:09 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/16 12:49:22 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Loads all the files needed and saves theme on the different
variables that we will access later */

void	ft_load_files2(t_game *g)
{
	g->img.f2 = mlx_xpm_file_to_image(g->ptr, "xpm/F_REV.xpm",
			&g->img.tile_x, &g->img.tile_y);
	g->img.f3 = mlx_xpm_file_to_image(g->ptr, "xpm/F_REV2.xpm",
			&g->img.tile_x, &g->img.tile_y);
	g->img.foe = mlx_xpm_file_to_image(g->ptr, "xpm/FOE3.xpm",
			&g->img.tile_x, &g->img.tile_y);
	g->img.foe2 = mlx_xpm_file_to_image(g->ptr, "xpm/FOE4.xpm",
			&g->img.tile_x, &g->img.tile_y);
	g->img.sprite = g->img.c;
	g->img.sprite2 = g->img.foe;
	g->img.sp = g->img.f;
}

void	ft_load_files(t_game *g)
{
	g->img.w = mlx_xpm_file_to_image(g->ptr, "xpm/W.xpm",
			&g->img.tile_x, &g->img.tile_y);
	g->img.c = mlx_xpm_file_to_image(g->ptr, "xpm/C.xpm",
			&g->img.tile_x, &g->img.tile_y);
	g->img.c2 = mlx_xpm_file_to_image(g->ptr, "xpm/C_REV.xpm",
			&g->img.tile_x, &g->img.tile_y);
	g->img.p = mlx_xpm_file_to_image(g->ptr, "xpm/P.xpm",
			&g->img.tile_x, &g->img.tile_y);
	g->img.e = mlx_xpm_file_to_image(g->ptr, "xpm/E1.xpm",
			&g->img.tile_x, &g->img.tile_y);
	g->img.e2 = mlx_xpm_file_to_image(g->ptr, "xpm/E2.xpm",
			&g->img.tile_x, &g->img.tile_y);
	g->img.f = mlx_xpm_file_to_image(g->ptr, "xpm/F.xpm",
			&g->img.tile_x, &g->img.tile_y);
	ft_load_files2(g);
}
