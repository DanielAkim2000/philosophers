/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:57:19 by demane            #+#    #+#             */
/*   Updated: 2026/02/18 11:29:48 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine_bonus.h"

void	ft_process_philo_bonus(t_philo *p)
{
	sem_wait(p->rules->forks);
	sem_wait(p->rules->meal);
	if (p->should_exit)
	{
		sem_post(p->rules->meal);
		sem_post(p->rules->forks);
		return ;
	}
	sem_post(p->rules->meal);
	ft_safe_print_bonus(p, "has taken a fork");
	sem_wait(p->rules->forks);
	sem_wait(p->rules->meal);
	if (p->should_exit)
	{
		sem_post(p->rules->meal);
		sem_post(p->rules->forks);
		sem_post(p->rules->forks);
		return ;
	}
	sem_post(p->rules->meal);
	ft_safe_print_bonus(p, "has taken a fork");
}

void	ft_sleep_philo_bonus(t_philo *p)
{
	ft_safe_print_bonus(p, "is sleeping");
	ft_usleep_bonus(p->rules->t_sleep, p);
}

void	ft_think_bonus(t_philo *p)
{
	long	think_time;
	long	time_margin;

	ft_safe_print_bonus(p, "is thinking");
	if (p->rules->nb_philo % 2 != 0)
	{
		time_margin = p->rules->t_die - (p->rules->t_eat + p->rules->t_sleep);
		if (time_margin > 0)
			think_time = time_margin / 2;
		else
			think_time = 0;
		if (think_time > 0)
			ft_usleep_bonus(think_time, p);
	}
}
