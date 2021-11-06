/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:10:26 by ldurante          #+#    #+#             */
/*   Updated: 2021/11/05 20:40:21 by ldurante         ###   ########.fr       */
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

typedef struct s_sim
{
	int				n_philo;
	int				n_meals;
	long long 		start_time;
	long long 		end_time;
	long long 		to_die;
	long long 		to_eat;
	long long 		to_sleep;
	pthread_t		*philo_thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	sleep;
	pthread_mutex_t	meals;
}	t_sim;

typedef	struct s_philo
{
	int 			id;
	int 			left_fork;
	int				right_fork;
	int				meals_eaten;
	pthread_mutex_t *eat;
	t_sim 			*sim_state;
}	t_philo;


int			main(int argc, char **argv);
void		create_threads(t_philo *p, t_sim *sim);
long long	timestamp(void);
void		ft_error(char *str);

#endif