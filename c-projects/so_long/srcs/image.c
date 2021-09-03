/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:52:09 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/03 14:05:13 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_load_files(t_game *mlx, t_image *img)
{
	img->w = mlx_xpm_file_to_image(mlx->ptr, "xpm/W.xpm",
			&mlx->size.x, &mlx->size.y);
	img->w_add = mlx_get_data_addr(img->w, &img->bpp, &img->line, &img->endian);
	img->c = mlx_xpm_file_to_image(mlx->ptr, "xpm/C2.xpm",
			&mlx->size.x, &mlx->size.y);
	img->c_add = mlx_get_data_addr(img->c, &img->bpp, &img->line, &img->endian);
	img->p = mlx_xpm_file_to_image(mlx->ptr, "xpm/P2.xpm",
			&mlx->size.x, &mlx->size.y);
	img->p_add = mlx_get_data_addr(img->p, &img->bpp, &img->line, &img->endian);
	img->e = mlx_xpm_file_to_image(mlx->ptr, "xpm/E.xpm",
			&mlx->size.x, &mlx->size.y);
	img->e_add = mlx_get_data_addr(img->e, &img->bpp, &img->line, &img->endian);
	img->f = mlx_xpm_file_to_image(mlx->ptr, "xpm/F.xpm",
			&mlx->size.x, &mlx->size.y);
	img->f_add = mlx_get_data_addr(img->f, &img->bpp, &img->line, &img->endian);
}
