/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:42:11 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/03 17:11:52 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	int x;
	int y;
	
	ft_printf("**** FUNCION MIA ****\n");
	x = ft_printf(" %-.2d ", 0);
	printf("Length: %d\n", x);
	
	printf("**** FUNCION ORIGINAL ****\n");
	y = printf(" %-.2d ", 0);
	printf("Length: %d\n", y);
	
	return (0);
}