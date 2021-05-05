/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:30:19 by ldurante          #+#    #+#             */
/*   Updated: 2021/05/05 15:33:10 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open("text.txt", O_RDONLY);
	ret = get_next_line(fd, &line);
	while (ret >= 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
		if (ret == 0)
			break ;
		ret = get_next_line(fd, &line);
	}
	free(line);
	line = NULL;
	system("leaks a.out");
	close(fd);
	return (0);
}
