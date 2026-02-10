/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 00:35:22 by demane            #+#    #+#             */
/*   Updated: 2026/02/10 09:31:12 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine.h"

void	ft_monitor(t_philo *philos)
{
	int		i;
	long	now;
	int		nb_full;
	t_rules	*rules;

	rules = philos[0].rules;
	while (1)
	{
		nb_full = 0;
		i = 0;
		while (i < rules->nb_philo)
		{
			pthread_mutex_lock(&rules->meal);
			now = ft_gettime();
			if (now - philos[i].last_meal >= rules->t_die)
			{
				pthread_mutex_unlock(&rules->meal);
				pthread_mutex_lock(&rules->death);
				if (!rules->is_dead)
				{
					rules->is_dead = 1;
					pthread_mutex_unlock(&rules->death);
					pthread_mutex_lock(&rules->print);
					printf("%ld %d died\n",
						now - rules->start_time,
						philos[i].id);
					pthread_mutex_unlock(&rules->print);
				}
				pthread_mutex_unlo k(&rules->death);
				return ;
			}
			if (rules->nb_meals > 0 && philos[i].is_full)
				nb_full++;
			pthread_mutex_unlock(&rules->meal);`
			i++;
		}
		if (rules->nb_meals > 0 && nb_full == rules->nb_philo)
			return ;
		usleep(500);
	}
}
