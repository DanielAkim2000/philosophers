/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:57:19 by demane            #+#    #+#             */
/*   Updated: 2026/02/15 14:38:43 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine_bonus.h"

void	ft_process_philo_bonus(t_philo *p)
{
	sem_wait(p->rules->forks);
	ft_safe_print_bonus(p, "has taken a fork");
	sem_wait(p->rules->forks);
	ft_safe_print_bonus(p, "has taken a fork");
}

void	ft_sleep_philo_bonus(t_philo *p)
{
	sem_wait(p->rules->death);
	if (p->rules->is_dead)
	{
		sem_post(p->rules->death);
		return ;
	}
	sem_post(p->rules->death);
	ft_safe_print_bonus(p, "is sleeping");
	ft_usleep_bonus(p->rules->t_sleep, p);
}

void	ft_think_bonus(t_philo *p)
{
	long	think_time;
	long	time_margin;

	sem_wait(p->rules->death);
	if (p->rules->is_dead)
	{
		sem_post(p->rules->death);
		return ;
	}
	sem_post(p->rules->death);
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
