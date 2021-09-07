/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:52:09 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/07 01:58:52 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_load_files(t_game *g)
{
	g->img.w = mlx_xpm_file_to_image(g->ptr, "xpm/W.xpm",
			&g->size_x, &g->size_y);
	g->img.w_add = mlx_get_data_addr(g->img.w, &g->img.bpp, &g->img.line, &g->img.endian);
	g->img.c = mlx_xpm_file_to_image(g->ptr, "xpm/C2.xpm",
			&g->size_x, &g->size_y);
	g->img.c_add = mlx_get_data_addr(g->img.c, &g->img.bpp, &g->img.line, &g->img.endian);
	g->img.c2 = mlx_xpm_file_to_image(g->ptr, "xpm/C2_REV.xpm",
			&g->size_x, &g->size_y);
	g->img.c2_add = mlx_get_data_addr(g->img.c2, &g->img.bpp, &g->img.line, &g->img.endian);
	g->img.p = mlx_xpm_file_to_image(g->ptr, "xpm/P2.xpm",
			&g->size_x, &g->size_y);
	g->img.p_add = mlx_get_data_addr(g->img.p, &g->img.bpp, &g->img.line, &g->img.endian);
	g->img.e = mlx_xpm_file_to_image(g->ptr, "xpm/E1.xpm",
			&g->size_x, &g->size_y);
	g->img.e_add = mlx_get_data_addr(g->img.e, &g->img.bpp, &g->img.line, &g->img.endian);
	g->img.e2 = mlx_xpm_file_to_image(g->ptr, "xpm/E2.xpm",
			&g->size_x, &g->size_y);
	g->img.e2_add = mlx_get_data_addr(g->img.e2, &g->img.bpp, &g->img.line, &g->img.endian);
	g->img.f = mlx_xpm_file_to_image(g->ptr, "xpm/F.xpm",
			&g->size_x, &g->size_y);
	g->img.f_add = mlx_get_data_addr(g->img.f, &g->img.bpp, &g->img.line, &g->img.endian);
}
