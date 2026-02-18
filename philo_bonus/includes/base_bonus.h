/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:55:26 by demane            #+#    #+#             */
/*   Updated: 2026/02/18 11:15:16 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_BONUS_H
# define BASE_BONUS_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct timeval	t_timeval;

typedef struct s_rules
{
	int					nb_philo;
	long				t_die;
	long				t_eat;
	long				t_sleep;
	int					nb_meals;
	long				start_time;
	sem_t				*print;
	sem_t				*death;
	sem_t				*meal;
	sem_t				*forks;
}						t_rules;

typedef struct s_philo
{
	int					id;
	long				last_meal;
	int					meals_eaten;
	t_rules				*rules;
	int					is_full;
	sem_t				*meal_p;
	pid_t				pid;
	int					should_exit;
}						t_philo;

#endif
