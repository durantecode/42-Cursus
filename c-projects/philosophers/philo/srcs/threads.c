/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:46:22 by ldurante          #+#    #+#             */
/*   Updated: 2021/11/04 23:49:16 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_forks(t_philo *philo)
{
	// printf("PID: %d\n", p->id);
	// p->l_fork = (p->id + 1) % p->n_philo;
	// pthread_mutex_lock(&p[p->id].right_fork);
	printf("Philo %d has taken a fork\n", philo->id);
	// pthread_mutex_lock(&p[p->id].left_fork);
	printf("Philo %d has taken a fork\n", philo->id);
}

void	leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->sim_state->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->sim_state->forks[philo->left_fork]);
}

void	*routine(void *arg_p)
{
	t_philo	*philo;

	philo = (t_philo *) arg_p;
	int i = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->sim_state->forks[philo->right_fork]);
		printf("Philo %d has taken a fork\n", philo->id);
		pthread_mutex_lock(&philo->sim_state->forks[philo->left_fork]);
		printf("Philo %d has taken a fork\n", philo->id);
		// pthread_mutex_unlock(&p->fork);
		// take_forks(p);
		// leave_forks(philo);
		// if (p->id == 4)
		// 	break;
		i++;
	}
	return (0);
}

void	create_threads(t_philo *philo, t_sim *sim)
{
	// pthread_t	philo_id;
	int i;

	i = 0;
	while (i < sim->n_philo)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % sim->n_philo;
		philo[i].sim_state = sim;
		i++;
	}
	i = 0;
	while (i < sim->n_philo)
	{
		if ((pthread_create(&sim->philo_thread[i], NULL, &routine, &philo[i])) != 0)
			ft_error("philo: failed to create threads");
		pthread_detach(sim->philo_thread[i]);
		// pthread_mutex_init(&p[i].left_fork, NULL);
		// pthread_mutex_init(&p[i].right_fork, NULL);
		i++;
	}
	// i = 0;
	// while (i < p->n_philo)
	// {
	// 	if ((pthread_join(philo_id, NULL)) != 0)
	// 		ft_error("philo: failed to create threads");
	// 	i++;
	// }
	// i = 0;
	// while (i < p[0].n_philo)
	// 	pthread_mutex_destroy(&p[i++].fork);
	// pthread_mutex_init(&p->left_fork, NULL);
	// pthread_mutex_init(&p->right_fork, NULL);
}
