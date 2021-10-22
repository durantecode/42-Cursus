/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:15:30 by ldurante          #+#    #+#             */
/*   Updated: 2021/10/22 15:21:24 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	main(int argc, char **argv)
{
	long long i;
	long long n;

	int p = i + 200;
	i = 0;
	printf("start seconds: %lld\n", i);
	while(i < 1000)
	{	
		n = timestamp();
		printf("miliseconds: %d\n", p);
		i++;
	}
	return (0);
}