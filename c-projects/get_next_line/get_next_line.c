/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:51:10 by ldurante          #+#    #+#             */
/*   Updated: 2021/04/28 23:52:08 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_line_len(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\n' && str[x] != '\0')
		x++;
	if (str[x] == '\0')
		return (0);
	return (x);
}

int	get_next_line(int fd, char **line)
{
	size_t	file_size;
	static char *saved[4096];
	char	buff[BUFFER_SIZE + 1];
	char	*aux;
	char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 1)
		return (-1);
	file_size = read(fd, buff, BUFFER_SIZE);
	buff[file_size] = '\0';
	if (ft_strchr(buff, '\n'))
	{
		if (!saved[fd])
		{
			tmp = ft_strdup(buff);
			ft_strlcpy(*line, tmp, ft_line_len(tmp) + 1);
			saved[fd] = ft_strchr(tmp, '\n') + 1;
			return (1);
		}
		else
		{
			saved[fd] = ft_strjoin(saved[fd], buff);
			ft_strlcpy(*line, saved[fd], ft_line_len(saved[fd]) + 1);
			free (saved[fd]);
			saved[fd] = ft_strchr(saved[fd], '\n') + 1;
			return (1);
		}
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
		ft_strlcpy(*line, aux, ft_line_len(aux) + 1);
		saved[fd] = ft_strchr(aux, '\n') + 1;
		return (1);
	}
	return (0);
}

int		main(void)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open("text.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
	}
	close(fd);
	free(line);
	return (0);
}