/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 22:22:21 by ldurante          #+#    #+#             */
/*   Updated: 2021/10/06 18:45:11 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int argc, char **argv)
{
		int     fd[2];
		int		fd2;
		pid_t   childpid;
		char    buff[80];
		int status;

		pipe(fd);
		childpid = fork();
		
		if (childpid == 0)
		{
			close(fd[READ_END]);
			fd2 = open("file1", O_RDONLY);
			dup2(fd2, STDIN_FILENO);
			close(fd2);
			dup2(fd[WRITE_END], STDOUT_FILENO);
			execlp("/usr/bin/grep", "grep", "5", NULL);
			close(fd[WRITE_END]);
		}
		else
		{
			close(fd[WRITE_END]);
			childpid = fork();
			if (childpid == 0)
			{
				fd2 = open("file2", O_WRONLY);
				dup2(fd[READ_END], STDIN_FILENO);
          		close(fd[READ_END]);
				
				dup2(fd2, STDOUT_FILENO);
				execlp("/usr/bin/wc", "wc", "-w", NULL);
			}
			else
				close(fd[READ_END]); 
		}
		// wait(&status);   
   		// wait(&status);   
		return(0);
}