/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:56:37 by ldurante          #+#    #+#             */
/*   Updated: 2021/11/26 01:23:52 by ldurante         ###   ########.fr       */
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
	if (err == 2 && (err = 1))
		write(1, "Error: Operation file corrupted\n", 32);
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
	draw	el;
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
					res = fscanf(fd, "\n%c %f %f %f %c", &el.t, &el.x, &el.y, &el.r, &el.c);
					if (res == -1)
						return (err_msg(fd, 0));
					else if (res != 5 || el.r <= 0 || (el.t != 'c' && el.t != 'C'))
						break ;
					for (int line = 0; line < H; line++)
					{
						for (int col = 0; col < W; col++)
						{
							sqr = sqrtf((col - el.x) * (col -el.x) + (line - el.y) * (line - el.y));
							if (sqr <= el.r)
							{
								if (el.t == 'c' && sqr + 1 > el.r)
									TAB[line][col] = el.c;
								else if (el.t == 'C')
									TAB[line][col] = el.c;
							}
						}
					}
				}
			}
		}
	}
	return (err_msg(fd, 2));
}