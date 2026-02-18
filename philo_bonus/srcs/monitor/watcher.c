/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:47:06 by demane            #+#    #+#             */
/*   Updated: 2026/02/18 11:23:52 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/watcher.h"

void	*ft_watcher(void *arg)
{
	t_philo	*p;
	long	current_time;
	long	last_meal;

	p = (t_philo *)arg;
	while (1)
	{
		usleep(1000);
		current_time = ft_gettime_bonus();
		sem_wait(p->rules->meal);
		if (p->is_full)
			return (sem_post(p->rules->meal), (void *)0);
		last_meal = p->last_meal;
		sem_post(p->rules->meal);
		if (current_time - last_meal >= p->rules->t_die)
		{
			sem_wait(p->rules->death);
			sem_wait(p->rules->meal);
			p->should_exit = 1;
			sem_post(p->rules->meal);
			sem_post(p->rules->forks);
			sem_wait(p->rules->print);
			printf("%ld %d died\n", current_time - p->rules->start_time, p->id);
			return ((void *)1);
		}
	}
}
