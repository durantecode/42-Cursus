/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 22:11:25 by ldurante          #+#    #+#             */
/*   Updated: 2021/10/15 15:50:43 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
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

/* PIPEX FUNCTIONS */

int		main(int argc, char **argv, char **env);
void	pipex(t_pgm *pgm, char **argv, char **env);
void	free_matrix(char **matrix);
void	ft_exit(t_pgm *pgm, char *str, char *result);

/* UTILS FUNCTIONS */

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

#endif