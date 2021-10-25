/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:15:30 by ldurante          #+#    #+#             */
/*   Updated: 2021/10/25 20:24:28 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int		parse_arg(t_philo *p, int argc, char **argv)
{
	p->n_philo = ft_atoi(argv[1]);
	p->forks = ft_atoi(argv[1]);
	p->to_die = ft_atoi(argv[2]);
	p->to_eat = ft_atoi(argv[3]);
	p->to_sleep = ft_atoi(argv[4]);
	p->meals = ft_atoi(argv[5]);
}

int		check_argv(t_philo *p, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		printf("philo: usage: n_philo to_die to_eat to_sleep meals");
}

int	main(int argc, char **argv)
{
	t_philo p;
	long long i;
	long long n;

	i = timestamp();
	printf("start seconds: %lld\n", i);
	while(i < 10)
	{	
		n = timestamp();
		printf("miliseconds: %d\n", p);
		i++;
	}
	return (0);
}