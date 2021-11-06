/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:46:22 by ldurante          #+#    #+#             */
/*   Updated: 2021/11/06 02:28:30 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->sim_state->forks[philo->left_fork]);
	printf("Philo %d has taken fork n: %d\n", philo->id, philo->left_fork);
	pthread_mutex_lock(&philo->sim_state->forks[philo->right_fork]);
	printf("Philo %d has taken fork n: %d\n", philo->id, philo->right_fork);
	printf("Philo %d is eating\n", philo->id);
	usleep(200);
	pthread_mutex_unlock(&philo->sim_state->forks[philo->left_fork]);
	// printf("Philo %d has dropped fork n: %d\n", philo->id, philo->left_fork);
	pthread_mutex_unlock(&philo->sim_state->forks[philo->right_fork]);
	// printf("Philo %d has dropped fork n: %d\n", philo->id, philo->right_fork);
	usleep(200);
	// usleep(philo->sim_state->to_sleep * 1000);
}

void	eat_and_leave_forks(t_philo *philo)
{
	// pthread_mutex_lock(philo[philo->id].eat);
	philo->meals_eaten++;
	// printf("Philo %d is eating\n", philo->id);
	// usleep(philo->sim_state->to_eat * 1);
	// pthread_mutex_unlock(philo[philo->id].eat);
}

void	*routine(void *arg_p)
{
	t_philo	*philo;

	philo = (t_philo *) arg_p;
	while (1)
	{
		take_forks(philo);
		// printf("Philo %d is eating\n", philo->id);
		// usleep(philo->sim_state->to_eat * 1000);
		// eat_and_leave_forks(philo);
	}
	return (0);
}

void	create_threads(t_philo *philo, t_sim *sim)
{
	int i;

	i = 0;
	while (i < sim->n_philo)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % sim->n_philo;
		philo[i].sim_state = sim;
		philo[i].eat = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo[i].eat, NULL);
		i++;
	}
	i = 0;
	while (i < sim->n_philo)
	{
		if ((pthread_create(&sim->philo_thread[i], NULL, &routine, &philo[i])) != 0)
			ft_error("philo: failed to create threads");
		pthread_detach(sim->philo_thread[i]);
		usleep(50);
		i++;
	}
}
