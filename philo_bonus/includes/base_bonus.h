/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:15:19 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 05:26:27 by demane           ###   ########.fr       */
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

typedef struct s_rules
{
	int			nb_philo;
	long		t_die;
	long		t_eat;
	long		t_sleep;
	int			nb_meals;
	long		start_time;
	pid_t		*pids;
	sem_t		*forks;
	sem_t		*print;
}				t_rules;

typedef struct s_philo
{
	int			id;
	int			meals_eaten;
	int			is_dead;
	long		last_meal;
	char		meal_name[32];
	sem_t		*meal_sem;
	char		dead_name[32];
	sem_t		*dead_sem;
	pthread_t	routine;
	pthread_t	monitor;
	t_rules		*rules;
}				t_philo;

#endif
