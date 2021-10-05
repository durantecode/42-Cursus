/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 22:22:21 by ldurante          #+#    #+#             */
/*   Updated: 2021/10/05 18:29:34 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int argc, char **argv)
{
		int     fd[2], nbytes;
		pid_t   childpid;
		char	*str;
		char    readbuffer[80];

		pipe(fd);
		fd[0] = open("file1", O_RDONLY);
		nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
		
		if((childpid = fork()) == -1)
		{
				perror("fork");
				exit(1);
		}

		if(childpid == 0)
		{
				/* Child process closes up input side of pipe */
				close(fd[0]);

				/* Send "string" through the output side of pipe */
				write(fd[1], str, (strlen(str)+1));
				exit(0);
		}
		else
		{
				/* Parent process closes up output side of pipe */
				close(fd[1]);

				/* Read in a string from the pipe */
				nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
				printf("Received string: %s", readbuffer);
		}
		return(0);
}