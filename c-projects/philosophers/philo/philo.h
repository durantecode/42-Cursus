/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:10:26 by ldurante          #+#    #+#             */
/*   Updated: 2021/10/27 00:02:19 by ldurante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

int x = 0;
pthread_mutex_t	mutex;

typedef struct s_philo
{
	long long start_time;
	int n_philo;
	int n_forks;
	long long to_die;
	long long to_eat;
	long long to_sleep;
	int	n_meals;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	eat;
	pthread_mutex_t	sleep;
	pthread_mutex_t	meals;
	
}	t_philo;

int		main(int argc, char **argv);

#endif