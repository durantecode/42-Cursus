/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:51:10 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/23 17:22:46 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	static int	x = 0;

	// x = 0;
	while (str[x] != '\n')
	{
		ft_putchar(str[x]);
		x++;
	}
	x++;
}

char	*open_file(void)
{
	unsigned int	file_size;
	int				fd;
	char			*text;

	text = malloc(BUFFER_SIZE + 1);
	fd = open("text.txt", O_RDONLY);
	file_size = read(fd, text, BUFFER_SIZE);
	text[file_size] = '\0';
	close(fd);
	return (text);
}

// int	get_next_line(int fd, char **line)
// {
	
// }

int		main(void)
{
	char *text;

	text = open_file();
	while (*text != '\0')
	{
		ft_putstr(text);
		ft_putchar('\n');
	}
	free(text);
	return (0);
}