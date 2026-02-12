/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:14:50 by demane            #+#    #+#             */
/*   Updated: 2026/02/11 10:18:07 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct timeval	t_timeval;

typedef struct s_rules
{
	int				nb_philo;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	int				nb_meals;
	int				is_dead;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	meal;
}	t_rules;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long			last_meal;
	int				meals_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			start_time;
	t_rules			*rules;
	int				is_full;
}	t_philo;

#endif
