/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:42:11 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/17 18:59:02 by ldurante         ###   ########.fr       */
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
	x = ft_printf(" %10p %10p ", 1, -1);
	printf("Length: %d\n", x);
	
	printf("**** FUNCION ORIGINAL ****\n");
	y = printf(" %10p %p ", 1, "1");
	printf("Length: %d\n", y);

	//system("leaks a.out");
	return (0);
}