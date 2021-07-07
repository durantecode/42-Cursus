/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:57:06 by ldurante          #+#    #+#             */
/*   Updated: 2021/07/07 19:18:57 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int x;
	int y;
	char *line;
	
	fd = open("text.txt", O_RDONLY);
	x = get_next_line(&line);
	y = 1;
	while (x >= 0)
	{
		printf("line %d read ---> %s\n", y, line);
		free(line);
		line = NULL;
		if (x == 0)
			break ;
		x = get_next_line(&line);
		y++;		
	}
	return (0);
}