/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:16:00 by ldurante          #+#    #+#             */
/*   Updated: 2021/09/07 01:25:54 by ldurante         ###   ########.fr       */
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

typedef struct s_map
{
	char 	**map;
	int 	map_x;
	int 	map_y;
}	t_map;

typedef struct	s_image
{
	int		bpp;
	int		line;
	int		endian;
	void	*w;
	void	*c;
	void	*c2;
	void	*p;
	void	*e;
	void	*e2;
	void	*f;
	char	*w_add;
	char	*c_add;
	char	*c2_add;
	char	*p_add;
	char	*e_add;
	char	*e2_add;
	char	*f_add;
}   t_image;

typedef struct s_game
{
	void	*ptr;
	void	*win;
	int		size_x;
	int		size_y;
	int		start_x;
	int		start_y;
	int		c_count;
	int		frames;
	t_image	img;
	t_map	m;
}	t_game;

int		main(int argc, char **argv);
int		get_next_line(int fd, char **line);
void	ft_map(int fd, char *argv, t_game *g);
void	ft_draw_map(t_game *g);
void	ft_load_files(t_game *g);
int		ft_error(int n);

#endif