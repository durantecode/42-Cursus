/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durante <durante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:42:11 by ldurante          #+#    #+#             */
/*   Updated: 2021/06/03 01:14:06 by durante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	int x;
	int y;
	
	ft_printf("**** FUNCION MIA ****\n");
	x = ft_printf(" %*.5s %*.5s ", -10, "123", -10, "4567");
	printf("Length: %d\n", x);
	
	printf("**** FUNCION ORIGINAL ****\n");
	y = printf(" %*.5s %*.5s ", -10, "123", -10, "4567");
	printf("Length: %d\n", y);
	
	return (0);
}