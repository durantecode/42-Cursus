/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:42:11 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/23 21:20:46 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <limits.h>

int main(void)
{
	int x;
	int y;
	
	ft_printf("**** FUNCION MIA ****\n");
	x = ft_printf("%-1.0d", 0);
	printf("Length: %d\n", x);
	
	printf("**** FUNCION ORIGINAL ****\n");
	y = printf("%-1.0d", 0);
	printf("Length: %d\n", y);

	//system("leaks a.out");
	return (0);
} 