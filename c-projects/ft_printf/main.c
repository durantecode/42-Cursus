/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:42:11 by ldurante          #+#    #+#             */
/*   Updated: 2021/05/18 22:55:36 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	int x;
	int y;
	
	ft_printf("**** FUNCION MIA ****\n");
	x = ft_printf("hola %d, %i, %s, %c, adios\n", 234, 678, "string", 'G');
	printf("%d\n", x);
	
	printf("**** FUNCION ORIGINAL ****\n");
	y = printf("hola %d, %i, %s, %c, adios\n", 234, 678, "string", 'G');
	printf("%d\n", y);
	
	return (0);
}