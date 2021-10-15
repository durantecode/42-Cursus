/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 22:22:29 by ldurante          #+#    #+#             */
/*   Updated: 2021/10/15 02:40:05 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_cmd_path(t_pgm *pgm, char *argv)
{
	char	*aux;
	char	*path;
	int		i;

	i = 0;
	pgm->cmd = ft_split(argv, ' ');
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
	get_cmd_path(pgm, argv[2]);
	if ((execve(pgm->cmd_path, pgm->cmd, env)) == -1)
	{
		free(pgm->cmd_path);
		free_matrix(pgm->cmd);
		ft_exit(pgm, "command not found: ", pgm->cmd[0]);
	}
}

void	parent(t_pgm *pgm, char **argv, char **env, int pid)
{
	close(pgm->pipe_fd[W_END]);
	pid = fork();
	if (pid < 0)
		ft_exit(pgm, "Could not create pipe", "");
	if (pid == 0)
	{
		pgm->fd_outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
		dup2(pgm->pipe_fd[R_END], STDIN_FILENO);
		close(pgm->pipe_fd[R_END]);
		dup2(pgm->fd_outfile, STDOUT_FILENO);
		close(pgm->fd_outfile);
		get_cmd_path(pgm, argv[3]);
		if ((execve(pgm->cmd_path, pgm->cmd, env)) == -1)
		{
			free(pgm->cmd_path);
			free_matrix(pgm->cmd);
			ft_exit(pgm, "command not found: ", pgm->cmd[0]);
		}
	}
	else
	{
		close(pgm->pipe_fd[R_END]);
		close(pgm->fd_infile);
		close(pgm->fd_outfile);
	}
}

void	pipex(t_pgm *pgm, char **argv, char **env)
{
	pid_t	pid;

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
	else
	{
		parent(pgm, argv, env, pid);
		free_matrix(pgm->split_path);
	}
	if (pid != 0)
		waitpid(pid, NULL, 0);
}
