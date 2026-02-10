/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:55:26 by demane            #+#    #+#             */
/*   Updated: 2026/02/10 18:49:53 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_BONUS_H
# define BASE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <semaphore.h>
# include <sys/time.h>
# include <fcntl.h>

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
	sem_t			*print;
	sem_t			*death;
	sem_t			*meal;
	sem_t			*forks;
}	t_rules;

typedef struct s_philo
{
	int				id;
	long			last_meal;
	int				meals_eaten;
	t_rules			*rules;
	int				is_full;
}	t_philo;

#endif
