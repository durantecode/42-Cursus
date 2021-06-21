/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:42:11 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/21 16:06:09 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <limits.h>

int main(void)
{
	int x;
	int y;

	static char *s_hidden = "hi low\0don't print me lol\0";
	
	ft_printf("**** FUNCION MIA ****\n");
	x = ft_printf("ultimate3 %*.*d %*.*s\n", 1, 50, 5000, 1, 0, "hey");
	printf("Length: %d\n", x);
	
	printf("**** FUNCION ORIGINAL ****\n");
	y = printf("ultimate3 %*.*d %*.*s\n", 1, 50, 5000, 1, 0, "hey");
	printf("Length: %d\n", y);

	//system("leaks a.out");
	return (0);
}