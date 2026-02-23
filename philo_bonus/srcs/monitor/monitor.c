/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:20:25 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 05:26:27 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/monitor_bonus.h"
#include "../../includes/routine_bonus.h"
#include "../../includes/utils_bonus.h"

static int	ft_check_death(t_philo *p)
{
	if (ft_get_time() - p->last_meal > p->rules->t_die)
	{
		p->is_dead = 1;
		sem_post(p->meal_sem);
		sem_wait(p->rules->print);
		printf("%ld %d died\n",
			ft_get_time() - p->rules->start_time, p->id);
		sem_post(p->dead_sem);
		return (1);
	}
	if (p->rules->nb_meals != -1
		&& p->meals_eaten >= p->rules->nb_meals)
	{
		sem_post(p->meal_sem);
		sem_post(p->dead_sem);
		return (1);
	}
	return (0);
}

void	*ft_monitor(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (1)
	{
		sem_wait(p->meal_sem);
		if (p->is_dead)
		{
			sem_post(p->meal_sem);
			return (NULL);
		}
		if (ft_check_death(p))
			return (NULL);
		sem_post(p->meal_sem);
		usleep(500);
	}
	return (NULL);
}
