/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:51:10 by ldurante          #+#    #+#             */
/*   Updated: 2021/05/04 00:03:16 by ldurante         ###   ########.fr       */
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

int		ft_line_length(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\n' && str[x] != '\0')
		x++;
	if (str[x] == '\0')
		return (0);
	return (x);
}

int ft_copy_line(int fd, char **line, char **saved)
{
	char	*aux;
	int		len;

	len = ft_line_length(saved[fd]);
	if (ft_strchr(saved[fd], '\n'))
	{
		*line = ft_substr(saved[fd], 0, len);
		aux = ft_strdup(saved[fd] + len + 1);
		ft_strdel(&saved[fd]);
		saved[fd] = aux;
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
	int		file_size;
	static char *saved[4096];
	char	buff[BUFFER_SIZE + 1];
	char	*aux;

	if (!fd || fd > 4096 || !line)
		return (-1);
	while ((file_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[file_size] = '\0';
		if (!saved[fd])
			saved[fd] = ft_strdup("\0");
		aux = ft_strjoin(saved[fd], buff);
		ft_strdel(&saved[fd]);
		saved[fd] = aux;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (!file_size && !saved[fd])
		return (0);
	if (file_size == -1)
		return (-1);
	return (ft_copy_line(fd, line, saved));	
}		
			
// int		main(void)
// {
// 	char	*line;
// 	int		fd;
// 	int		ret;

// 	fd = open("text.txt", O_RDONLY);
// 	while ((ret = get_next_line(fd, &line)) > 0)
// 	{
// 		printf("%s\n", line);
// 	}
// 	printf("%s\n", line);
// 	//check_leaks();
// 	system("leaks a.out");
// 	close(fd);
// 	free(line);
// 	return (0);
// }
