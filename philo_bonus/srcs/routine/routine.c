/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:20:25 by demane            #+#    #+#             */
/*   Updated: 2026/02/24 00:07:42 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine_bonus.h"
#include "../../includes/utils_bonus.h"

static void	ft_routine_gap(t_philo *p)
{
	if (p->rules->nb_philo % 2 != 0 && p->id == p->rules->nb_philo)
		ft_usleep(p->rules->t_eat * 2, p);
	else if (p->id % 2 == 0)
		ft_usleep(p->rules->t_eat, p);
}

void	*ft_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	ft_routine_gap(p);
	while (1)
	{
		ft_eat_routine(p);
		sem_wait(p->meal_sem);
		if (p->is_dead)
		{
			sem_post(p->meal_sem);
			return (NULL);
		}
		sem_post(p->meal_sem);
		if (p->rules->nb_meals != -1 && p->meals_eaten >= p->rules->nb_meals)
		{
			sem_post(p->dead_sem);
			return (NULL);
		}
		ft_sleep_think(p);
	}
	return (NULL);
}
