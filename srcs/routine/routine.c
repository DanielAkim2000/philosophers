/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:40:32 by demane            #+#    #+#             */
/*   Updated: 2026/02/08 13:43:40 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine.h"

void	ft_take_forks(t_philo *p)
{
	if (p->rules->nb_philo == 1)
		return (ft_process_philo_one(p));
	if (p->id % 2 == 0)
		ft_process_philo_peer(p);
	else
		ft_process_philo_odd(p);
}

void	ft_eat(t_philo *p)
{
	pthread_mutex_lock(&p->rules->meal);
	p->last_meal = ft_gettime();
	p->meals_eaten++;
	if (p->rules->nb_meals > 0 && p->meals_eaten >= p->rules->nb_meals)
		p->is_full = 1;
	ft_safe_print(p, "is eating");
	pthread_mutex_unlock(&p->rules->meal);
	ft_usleep(p->rules->t_eat, p);
}

void	ft_put_forks(t_philo *p)
{
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}

void	ft_think(t_philo *p)
{
	if (p->rules->is_dead)
		return ;
	ft_safe_print(p, "is thinking");
}

void	*ft_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->id % 2 != 0)
		usleep(300);
	while (1)
	{
		if (p->rules->is_dead || p->is_full)
			break ;
		ft_take_forks(p);
		ft_eat(p);
		ft_put_forks(p);
		ft_sleep_philo(p);
		ft_think(p);
	}
	return (NULL);
}

