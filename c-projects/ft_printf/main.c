/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:42:11 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/24 20:18:45 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <limits.h>

int main(void)
{
	int x;
	int y;
	
	ft_printf("**** FUNCION MIA ****\n");
	x = ft_printf("HOLA: %-*.*s", 1, -1, "HOLA");
	printf("Length: %d\n", x);
	
	printf("**** FUNCION ORIGINAL ****\n");
	y = printf("HOLA: %-*.*s", 1, -1, "HOLA");
	printf("Length: %d\n", y);

	//system("leaks a.out");
	//printf("FF");
	return (0);
} 