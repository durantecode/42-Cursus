/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:49:07 by ldurante          #+#    #+#             */
/*   Updated: 2021/05/11 17:39:18 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;
	int		i;
	char 	*arg;
	
	i = 0;
	counter = ft_strlen(format);
	va_start(args, format);
	while (i < counter)
	{
		arg = va_arg(args, char *);
		printf("%s\n", arg);
		i++;
	}
	va_end(args);
	return (counter);
}
