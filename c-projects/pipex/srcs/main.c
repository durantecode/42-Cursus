/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 22:22:21 by ldurante          #+#    #+#             */
/*   Updated: 2021/10/15 02:09:44 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_exit(t_pgm *pgm, char *message, char *result)
{
	if (pgm->split_path)
		free_matrix(pgm->split_path);
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(message, 2);
	ft_putendl_fd(result, 2);
	exit (0);
}

void	get_path(t_pgm *pgm, char **env)
{
	int	i;
	int	path_ok;

	i = 0;
	path_ok = 0;
	while (env[i] != '\0')
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			pgm->full_path = ft_strdup(env[i]);
			path_ok = 1;
		}
		i++;
	}
	if (path_ok)
	{
		pgm->split_path = ft_split(pgm->full_path, ':');
		free(pgm->full_path);
	}
	else
	{
		free(pgm->full_path);
		ft_exit(pgm, "Could not find correct PATH", "");
	}
}

void	leaks(void)
{
	system("leaks pipex");
}

int	main(int argc, char **argv, char **env)
{
	t_pgm	pgm;

	// atexit(leaks);
	if (argc != 5)
		ft_exit(&pgm, "usage: ./pipex infile cmd1 cmd2 outfile", "");
	get_path(&pgm, env);
	pipex(&pgm, argv, env);
	close(pgm.fd_infile);
	close(pgm.fd_outfile);
	// while(1);
	return (0);
}
