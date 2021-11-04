/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:15:30 by ldurante          #+#    #+#             */
/*   Updated: 2021/11/04 23:28:38 by ldurante         ###   ########.fr       */
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

int		parse_arg(t_sim *sim, int argc, char **argv)
{
	int i;

	sim->n_philo = ft_atoi(argv[1]);
	sim->to_die = (long long)ft_atoi(argv[2]);
	sim->to_eat = (long long)ft_atoi(argv[3]);
	sim->to_sleep = (long long)ft_atoi(argv[4]);
	sim->n_meals = 0;
	if (argc == 6)
		sim->n_meals = ft_atoi(argv[5]);
	sim->start_time = timestamp();
	sim->philo_thread = malloc(sizeof(pthread_t) * sim->n_philo);
	sim->forks = malloc(sizeof(pthread_mutex_t) * sim->n_philo);
	i = 0;
	while (i < sim->n_philo)
	{
		if (pthread_mutex_init(&sim->forks[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

void	check_arg(int argc, char **argv)
{
	int	i;
	int j;

	if (argc < 5 || argc > 6)
		ft_error("philo: usage: [n_philo] [time_to_die] \
				[time_to_eat] [time_to_sleep] [meals]");
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
	t_philo *philo;
	t_sim	sim;
	int		i;

	// p.start_time = timestamp();
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
		// return (1);
	check_arg(argc, argv);
	parse_arg(&sim, argc, argv);
	create_threads(philo, &sim);
	i = 0;
	while (i < sim.n_philo)
	{
		pthread_mutex_destroy(&sim.forks[i]);
		i++;
	}
	// p.end_time = timestamp();
	// printf("TIME: %lldms\n", p.end_time - p.start_time);
	return (0);
}