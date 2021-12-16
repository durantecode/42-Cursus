/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:56:37 by ldurante          #+#    #+#             */
/*   Updated: 2021/12/14 14:58:35 by ldurante         ###   ########.fr       */
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
char	**TAB;

typedef struct draw
{
	char	t;
	float	x;
	float	y;
	float	r;
	char	c;
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
			write(1, TAB[i], W);
			write(1, "\n", 1);
		}
	}
	if (fd)
		fclose(fd);
	return (err);
}

int		main(int ac, char **av)
{
	draw	draw;
	FILE	*fd;
	float	sqr;
	int		res;

	fd = NULL;
	if (ac != 2)
		return (err_msg(fd, 1));
	if ((fd = fopen(av[1], "r")))
	{
		if ((res = fscanf(fd, "%d %d %c", &W, &H, &BG)) == 3)
		{
			if (W > 0 && W <= 300 && H > 0 && H <= 300)
			{
				TAB = malloc(H * sizeof(char *));
				for (int i = 0; i < H; i++)
				{
					TAB[i] = malloc(W * sizeof(char));
					memset(TAB[i], BG, W);
				}
				while (1)
				{
					res = fscanf(fd, "\n%c %f %f %f %c",  draw.t,  draw.x,  draw.y,  draw.r,  draw.c);
					if (res == -1)
						return (err_msg(fd, 0));
					else if (res != 5 || draw.r <= 0 ||  (draw.t != 'c' && draw.t != 'C'))
						break ;
					for (int line = 0; line < H; line++)
					{
						for (int col = 0; col < W; col++)
						{
							sqr = sqrtf((col - draw.x) * (col - draw.x) + (line - draw.y) * (line - draw.y));
							if (sqr <= draw.r)
							{
								if  (draw.t == 'c' && sqr + 1 > draw.r)
									TAB[line][col] = draw.c;
								else if  (draw.t == 'C')
									TAB[line][col] = draw.c;
							}
						}
					}
				}
			}
		}
	}
	return (err_msg(fd, 2));
}