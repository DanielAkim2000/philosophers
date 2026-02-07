/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:14:50 by demane            #+#    #+#             */
/*   Updated: 2026/02/07 18:02:19 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

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
	long			start_time;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
}	t_rules;

typedef struct s_philo
{
	int				id; // id du philo // sert a identifier le philo
	pthread_t		thread; // thread du philo cree avec pthread_create // sert a executer sa vie
	long			last_meal; // en millisecond le timestamp du dernier repas // detecter la mort
	int				meals_eaten; // compteur de repas // gerer l argument optionnel
	pthread_mutex_t	*left_fork; // fourchette gauche du philo // mutex fourchette
	pthread_mutex_t	*right_fork; // foruchette droite du philo // mutex fourchette
	t_rules			*rules; // acces gloabl au rules;
}	t_philo;

#endif
