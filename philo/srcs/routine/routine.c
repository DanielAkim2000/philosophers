/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:40:32 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 05:26:27 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine.h"

static void	ft_routine_gap(t_philo *p)
{
	if (p->rules->nb_philo % 2 == 0)
	{
		if (p->id % 2 != 0)
			ft_usleep(p->rules->t_eat, p);
	}
	else
	{
		if (p->id == p->rules->nb_philo)
			ft_usleep(p->rules->t_eat * 2, p);
		else if (p->id % 2 != 0)
			ft_usleep(p->rules->t_eat, p);
	}
}

static void	ft_process_routine(t_philo *p)
{
	while (1)
	{
		pthread_mutex_lock(&p->rules->death);
		if (p->rules->is_dead)
		{
			pthread_mutex_unlock(&p->rules->death);
			break ;
		}
		pthread_mutex_unlock(&p->rules->death);
		pthread_mutex_lock(&p->rules->meal);
		if (p->is_full)
		{
			pthread_mutex_unlock(&p->rules->meal);
			break ;
		}
		pthread_mutex_unlock(&p->rules->meal);
		ft_take_forks(p);
		if (p->rules->nb_philo == 1)
			break ;
		ft_eat(p);
		ft_put_forks(p);
		ft_sleep_philo(p);
		ft_think(p);
	}
}

void	*ft_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	ft_routine_gap(p);
	ft_process_routine(p);
	return (NULL);
}
