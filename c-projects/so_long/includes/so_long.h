/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:16:00 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/02 22:55:52 by ldurante         ###   ########.fr       */
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

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ESC 53

typedef struct s_vector
{
	int 	x;
	int		y;
	
}	t_vector;

typedef struct s_map
{
	char 	**map;
	int 	map_x;
	int 	map_y;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*window;
	void	*wall;
	void	*collect;
	void	*player;
	void	*exit;
	char	*pixels;
	char	*pixels2;
	char	*pixels3;
	t_vector size;
//	t_map	map;
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


int		main(int argc, char **argv);
int		get_next_line(int fd, char **line);
void	ft_map(int fd, t_game *mlx, t_map *map, char *argv);
void	ft_draw_map(t_game *mlx, t_map *m);
int		ft_error(int n);

#endif