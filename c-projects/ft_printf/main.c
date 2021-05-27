/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durante <durante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:42:11 by ldurante          #+#    #+#             */
/*   Updated: 2021/05/27 18:01:24 by durante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	int x;
	int y;
	
	ft_printf("**** FUNCION MIA ****\n");
	x = ft_printf(" %4.3s %-4.3s ", "123", "4567");
	printf("Length: %d\n", x);
	
	printf("**** FUNCION ORIGINAL ****\n");
	y = printf(" %4.3s %-4.3s ", "123", "4567");
	printf("Length: %d\n", y);
	
	return (0);
}