/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:14:50 by demane            #+#    #+#             */
/*   Updated: 2026/02/16 11:55:30 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct timeval	t_timeval;

typedef struct s_rules
{
	int					nb_philo;
	long				t_die;
	long				t_eat;
	long				t_sleep;
	int					nb_meals;
	int					is_dead;
	pthread_mutex_t		print;
	pthread_mutex_t		death;
	pthread_mutex_t		meal;
	long				start_time;
	pthread_t			monitor;
}						t_rules;

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	long				last_meal;
	int					meals_eaten;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_rules				*rules;
	int					is_full;
}						t_philo;

#endif
