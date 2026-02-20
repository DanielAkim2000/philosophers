/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 00:35:22 by demane            #+#    #+#             */
/*   Updated: 2026/02/19 12:39:50 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine.h"

static int	ft_check_death(t_philo *philos, int i, t_rules *rules)
{
	long	now;

	now = ft_gettime();
	pthread_mutex_lock(&rules->meal);
	if (now - philos[i].last_meal >= rules->t_die)
	{
		pthread_mutex_lock(&rules->death);
		if (!rules->is_dead)
		{
			rules->is_dead = 1;
			pthread_mutex_unlock(&rules->death);
			pthread_mutex_lock(&rules->print);
			printf("%ld %d died\n", now - philos[i].rules->start_time,
				philos[i].id);
			pthread_mutex_unlock(&rules->print);
		}
		else
			pthread_mutex_unlock(&rules->death);
		pthread_mutex_unlock(&rules->meal);
		return (1);
	}
	pthread_mutex_unlock(&rules->meal);
	return (0);
}

void	ft_monitor(t_philo *philos)
{
	int		i;
	int		nb_full;
	t_rules	*rules;

	rules = philos[0].rules;
	while (1)
	{
		nb_full = 0;
		i = 0;
		while (i < rules->nb_philo)
		{
			if (ft_check_death(philos, i, rules))
				return ;
			pthread_mutex_lock(&rules->meal);
			if (rules->nb_meals > 0 && philos[i].is_full)
				nb_full++;
			pthread_mutex_unlock(&rules->meal);
			i++;
		}
		if (rules->nb_meals > 0 && nb_full == rules->nb_philo)
			return ;
		usleep(1000);
	}
}

void	*ft_routine_monitor(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	ft_monitor(p);
	return (NULL);
}
