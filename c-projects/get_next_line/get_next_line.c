/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:51:10 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/27 21:31:10 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		ft_putchar(str[x]);
		x++;
	}
}

int		ft_line_len(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\n' && str[x] != '\0')
	{
		x++;
	}
	if (str[x] == '\0')
		return (0);
	return (x);
}

int	get_next_line(int fd, char **line)
{
	size_t	file_size;
	//static char 	*read_fd[20]; Bonus?
	static char *saved[4096];
	char	buff[BUFFER_SIZE + 1];
	char	*aux;

	if (fd < 0 || BUFFER_SIZE <= 1)
		return (-1);
	file_size = read(fd, buff, BUFFER_SIZE);
	buff[file_size] = '\0';
	if (ft_strchr(buff, '\n'))
	{
		ft_strlcpy(*line, buff, ft_line_len(buff) + 1);
		ft_putstr(*line);
		saved[fd] = ft_strchr(buff, '\n') + 1;
		return (1);
	}
	else
	{
		if (!saved[fd])
			saved[fd] = ft_strdup(buff);
		else
			saved[fd] = ft_strjoin(saved[fd], buff);
		while (ft_line_len(saved[fd]) == 0 && file_size > 0)
		{
			file_size = read(fd, buff, BUFFER_SIZE);
			aux = ft_strjoin(saved[fd], buff);
			free (saved[fd]);
			saved[fd] = ft_strdup(aux);
		}
		free(saved[fd]);
		return (1);
	}
	ft_strlcpy(*line, aux, ft_line_len(aux) + 1);
	ft_putstr(*line);
	saved[fd] = ft_strchr(aux, '\n') + 1;
	return (0);
}

int		main(void)
{
	char	*line;
	int		fd;

	fd = open("text.txt", O_RDONLY);
//	printf("%d\n", get_next_line(fd, &line));
	get_next_line(fd, &line);
	ft_putchar('\n');
	get_next_line(fd, &line);
	ft_putchar('\n');
	// get_next_line(fd, &line);
	// ft_putchar('\n');
	// get_next_line(fd, &line);
	// ft_putchar('\n');
	// get_next_line(fd, &line);
	// ft_putchar('\n');
	// get_next_line(fd, &line);
	close(fd);
//	free(line);
	return (0);
}