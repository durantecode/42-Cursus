/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:16:00 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/01 00:58:01 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>

# define BUFFER_SIZE 10

typedef struct s_vector
{
	int x;
	int y;
	
}	t_vector;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*window;
	void	*image;
	char	*pixels;
	t_vector size;
}	t_game;

// typedef struct	s_image
// {
// 	void      *pointer;
// 	t_vector  size;
// 	char      *pixels;
// 	int       bits_per_pixel;
// 	int       line_size;
// 	int       endian;
// }   t_image;


int		main(void);
int		get_next_line(int fd, char **line);

#endif