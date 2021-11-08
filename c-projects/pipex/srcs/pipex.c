/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 22:22:29 by ldurante          #+#    #+#             */
/*   Updated: 2021/11/08 16:51:04 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_cmd_path(t_pgm *pgm)
{
	char	*aux;
	char	*path;
	int		i;

	i = 0;
	while (pgm->split_path[i])
	{
		aux = ft_strjoin(pgm->split_path[i], "/");
		path = ft_strjoin(aux, pgm->cmd[0]);
		if ((access(path, F_OK)) == 0)
			pgm->cmd_path = ft_strdup(path);
		free(aux);
		free(path);
		i++;
	}
}

void	child(t_pgm *pgm, char **argv, char **env)
{
	close(pgm->pipe_fd[R_END]);
	pgm->fd_infile = open(argv[1], O_RDONLY);
	if (pgm->fd_infile == -1)
		ft_exit(pgm, "no such file or directory: ", argv[1]);
	dup2(pgm->fd_infile, STDIN_FILENO);
	close(pgm->fd_infile);
	dup2(pgm->pipe_fd[W_END], STDOUT_FILENO);
	close(pgm->pipe_fd[W_END]);
	get_cmd_path(pgm);
	if ((execve(pgm->cmd_path, pgm->cmd, env)) == -1)
	{
		free(pgm->cmd_path);
		ft_exit(pgm, "command not found: ", pgm->cmd[0]);
	}
}

void	parent(t_pgm *pgm, char **argv, char **env, int pid)
{
	if (pid == 0)
	{
		dup2(pgm->pipe_fd[R_END], STDIN_FILENO);
		close(pgm->pipe_fd[R_END]);
		dup2(pgm->fd_outfile, STDOUT_FILENO);
		close(pgm->fd_outfile);
		pgm->cmd = ft_split(argv[3], ' ');
		get_cmd_path(pgm);
		if ((execve(pgm->cmd_path, pgm->cmd, env)) == -1)
		{
			free(pgm->cmd_path);
			ft_exit(pgm, "command not found: ", pgm->cmd[0]);
		}
	}
	close(pgm->pipe_fd[R_END]);
	close(pgm->fd_infile);
	close(pgm->fd_outfile);
}

void	pipex(t_pgm *pgm, char **argv, char **env)
{
	pid_t	pid;

	pgm->cmd = ft_split(argv[2], ' ');
	if ((pipe(pgm->pipe_fd)) == -1)
		ft_exit(pgm, "Could not create pipe", "");
	pid = fork();
	if (pid < 0)
	{
		close(pgm->pipe_fd[R_END]);
		close(pgm->pipe_fd[W_END]);
		ft_exit(pgm, "Could not create child process", "");
	}
	if (pid == 0)
		child(pgm, argv, env);
	waitpid(pid, NULL, 0);
	pid = fork();
	if (pid < 0)
		ft_exit(pgm, "Could not create pipe", "");
	close(pgm->pipe_fd[W_END]);
	parent(pgm, argv, env, pid);
	free(pgm->cmd_path);
	free_matrix(pgm->cmd);
	free_matrix(pgm->split_path);
}
