/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurante <ldurante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:10:26 by ldurante          #+#    #+#             */
/*   Updated: 2021/10/21 22:38:30 by ldurante         ###   ########.fr       */
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

typedef struct s_philo
{
	int n_philo;
	int n_forks;
	int to_die;
	int	to_eat;
	int to_sleep;
	
}	t_philo;

int		main(int argc, char **argv);

#endif