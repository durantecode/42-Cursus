/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 22:11:25 by ldurante          #+#    #+#             */
/*   Updated: 2021/10/15 02:12:38 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>

# define R_END 0
# define W_END 1

typedef struct s_pgm
{
	int		pipe_fd[2];
	int		fd_infile;
	int		fd_outfile;
	char	**cmd;
	char	*cmd_path;
	char	*full_path;
	char	**split_path;
}	t_pgm;

int		main(int argc, char **argv, char **env);
void	pipex(t_pgm *pgm, char **argv, char **env);
void	free_matrix(char **matrix);
void	ft_exit(t_pgm *pgm, char *str, char *result);

#endif