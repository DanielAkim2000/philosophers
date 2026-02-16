/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:47:06 by demane            #+#    #+#             */
/*   Updated: 2026/02/16 18:03:45 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/watcher.h"

void	*ft_watcher(void *arg)
{
	t_philo	*p;
	long	current_time;

	p = (t_philo *)arg;
	while (1)
	{
		current_time = ft_gettime_bonus();
		if (p->is_full)
			exit(0);
		if (current_time - p->last_meal >= p->rules->t_die)
		{
			sem_wait(p->rules->death);
			p->rules->is_dead = 1;
			sem_post(p->rules->death);
			sem_wait(p->rules->print);
			printf("%ld %d died\n", current_time - p->rules->start_time, p->id);
			sem_post(p->rules->print);
			exit(1);
		}
		usleep(1000);
	}
}
