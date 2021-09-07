/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:52:09 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/07 19:13:15 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_load_files(t_game *g)
{
	g->img.w = mlx_xpm_file_to_image(g->ptr, "xpm/W.xpm",
			&g->size_x, &g->size_y);
	g->img.c = mlx_xpm_file_to_image(g->ptr, "xpm/C2.xpm",
			&g->size_x, &g->size_y);
	g->img.c2 = mlx_xpm_file_to_image(g->ptr, "xpm/C2_REV.xpm",
			&g->size_x, &g->size_y);
	g->img.sprite = g->img.c;
	g->img.p = mlx_xpm_file_to_image(g->ptr, "xpm/P2.xpm",
			&g->size_x, &g->size_y);
	g->img.e = mlx_xpm_file_to_image(g->ptr, "xpm/E1.xpm",
			&g->size_x, &g->size_y);
	g->img.e2 = mlx_xpm_file_to_image(g->ptr, "xpm/E2.xpm",
			&g->size_x, &g->size_y);
	g->img.f = mlx_xpm_file_to_image(g->ptr, "xpm/F.xpm",
			&g->size_x, &g->size_y);
}
