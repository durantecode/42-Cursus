/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:51:10 by ldurante          #+#    #+#             */
/*   Updated: 2021/10/19 20:58:25 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_line_length(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	return (len);
}

int	ft_read_line(int fd, char **line, char **saved, int file_size)
{
	char	*aux;
	int		len;

	if (!file_size && !saved[fd])
		*line = ft_strdup("");
	else
	{
		len = ft_line_length(saved[fd]);
		if (saved[fd][len] == '\n')
		{
			*line = ft_substr(saved[fd], 0, len);
			aux = ft_strdup(saved[fd] + len + 1);
			free(saved[fd]);
			saved[fd] = aux;
			return (1);
		}
		else
			*line = ft_strdup(saved[fd]);
		free(saved[fd]);
		saved[fd] = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*saved[4096];
	int			file_size;
	char		buff[BUFFER_SIZE + 1];
	char		*aux;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	file_size = read(fd, buff, BUFFER_SIZE);
	while (file_size > 0)
	{
		buff[file_size] = '\0';
		if (!saved[fd])
			saved[fd] = ft_strdup("");
		aux = ft_strjoin(saved[fd], buff);
		free(saved[fd]);
		saved[fd] = aux;
		if (ft_strchr(buff, '\n'))
			break ;
		file_size = read(fd, buff, BUFFER_SIZE);
	}
	if (file_size == -1)
		return (-1);
	return (ft_read_line(fd, line, saved, file_size));
}		
