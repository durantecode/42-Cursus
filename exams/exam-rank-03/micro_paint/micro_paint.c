/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:42:06 by ldurante          #+#    #+#             */
/*   Updated: 2021/12/14 14:58:22 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		W;
int		H;
char	BG;
char 	*str;

typedef struct draw
{
	char		r;
	float		x;
	float		y;
	float		width;
	float		height;
	char		c;
} draw;

int		err_msg(FILE *fd, int err)
{
	if (err == 2)
	{
		err = 1;
		write(1, "Error: Operation file corrupted\n", 32);
	}
	else if (err == 1)
		write(1, "Error: argument \n", 16);
	else
	{
		for (int i = 0; i < H; i++)
		{
			write(1, str + (i * W), W);
			write(1, "\n", 1);
		}
	}
	if (fd)
		fclose(fd);
	return (err);
}

int	in_rectangle(float col, float line, draw *draw)
{
	if ((col < draw->x) || (draw->x + draw->width < col) || (line < draw->y) || (draw->y + draw->height < line))
		return (0);
	if ((col - draw->x < 1) || (draw->x + draw->width - col < 1) || (line - draw->y < 1) || (draw->y + draw->height - line < 1)) //borde
		return (2);
	return (1);
}

int		main(int ac, char **av)
{
	draw	draw;
	FILE	*fd;
	int		sqr;
	int		res;

	fd = NULL;
	if (ac != 2)
		return (err_msg(fd, 1));
	if ((fd = fopen(av[1], "r")))
	{
		if ((res = fscanf(fd, "%d %d %c\n", &W, &H, &BG)) == 3)
		{
			if (W > 0 && W <= 300 && H > 0 && H <= 300)
			{
				str = malloc(sizeof(char *) * (W * H));
				for (int i = 0; i < H * W; i++)
					str[i] = BG;
				while (1)
				{
					res = fscanf(fd, "%c %f %f %f %f %c\n", &draw.r, &draw.x, &draw.y, &draw.width, &draw.height, &draw.c);
					if (res == -1)
						return (err_msg(fd, 0));
					else if (res != 6 || draw.width <= 0 || draw.height <= 0 || (draw.r != 'r' && draw.r != 'R'))
						break ;
					for (int line = 0; line < H; line++)
					{
						for (int col = 0; col < W; col++)
						{
							sqr = in_rectangle((float)col, (float)line, &draw);
							if ((draw.r == 'r' && sqr == 2) || (draw.r == 'R' && sqr))
								str[(line * W + col)] = draw.c;
						}
					}
				}
			}
		}
	}
	return (err_msg(fd, 2));
}
