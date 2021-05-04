/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:30:19 by ldurante          #+#    #+#             */
/*   Updated: 2021/05/05 00:44:28 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open("text.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
		if (ret == 0)
			break ;
	}
	free(line);
	system("leaks a.out");
	close(fd);
	return (0);
}
