/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:51:10 by ldurante          #+#    #+#             */
/*   Updated: 2021/05/05 01:45:53 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strdel(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

int	ft_line_length(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\n' && str[x] != '\0')
		x++;
	if (str[x] == '\0')
		return (0);
	return (x);
}

int	ft_copy_line(int fd, char **line, char **saved, int file_size)
{
	char	*aux;
	int		len;

	if (!file_size && !saved[fd])
	{
		*line = ft_strdup("");
		return (0);
	}
	len = ft_line_length(saved[fd]);
	if (saved[fd][len] == '\n')
	{
		*line = ft_substr(saved[fd], 0, len);
		aux = ft_strdup(saved[fd] + len + 1);
		ft_strdel(&saved[fd]);
		saved[fd] = aux;
		if (saved[fd][0] == '\0')
			ft_strdel(&saved[fd]);
		return (1);
	}
	else if (ft_line_length(saved[fd]) == 0)
	{
		*line = ft_strdup(saved[fd]);
		ft_strdel(&saved[fd]);
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
		ft_strdel(&saved[fd]);
		saved[fd] = aux;
		if (ft_strchr(buff, '\n'))
			break ;
		file_size = read(fd, buff, BUFFER_SIZE);
	}
	if (file_size == -1)
		return (-1);
	return (ft_copy_line(fd, line, saved, file_size));
}		
