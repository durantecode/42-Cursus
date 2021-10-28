/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:15:30 by ldurante          #+#    #+#             */
/*   Updated: 2021/10/28 22:11:38 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit (0);
}

int		parse_arg(t_philo *p, int argc, char **argv)
{
	p->n_philo = ft_atoi(argv[1]);
	p->n_forks = ft_atoi(argv[1]);
	p->to_die = (long long)ft_atoi(argv[2]);
	p->to_eat = (long long)ft_atoi(argv[3]);
	p->to_sleep = (long long)ft_atoi(argv[4]);
	if (argc == 6)
		p->n_meals = ft_atoi(argv[5]);
	return (0);
}

void	*routine(void *arg_p)
{
	t_philo	*p;
	int i = 0;

	p = (t_philo *) arg_p;
	// printf("Total Meals: %d\n", p->n_meals);
	while(i < 100000)
	{
		pthread_mutex_lock(&mutex);
		// p->n_meals++;
		x++;
		pthread_mutex_unlock(&mutex);
		i++;
	}
	return (0);
}

void	create_threads(t_philo *p)
{
	pthread_t	philo[p->n_philo];
	int i;
	
	i = 1;
	pthread_mutex_init(&mutex, NULL);
	while (i <= p->n_philo)
	{
		pthread_create(philo + i, NULL, &routine, &p);
		printf("Thread Philo %d has started\n", i);
		i++;
	}
	i = 1;
	while (i <= p->n_philo)
	{
		pthread_join(philo[p->n_philo], NULL);
		printf("Thread Philo %d has ended execution\n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);
}

void	check_arg(int argc, char **argv)
{
	int	i;
	int j;

	if (argc < 5 || argc > 6)
		ft_error("philo: usage: n_philo to_die to_eat to_sleep meals");
	i = 1;
	while (argv[i] != '\0')
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				ft_error("philo: arguments must be numbers");
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo p;

	check_arg(argc, argv);
	parse_arg(&p, argc, argv);
	create_threads(&p);
	printf("Total Meals: %d\n", p.n_meals);
	printf("Total X: %d\n", x);
	p.start_time = timestamp();
	return (0);
}