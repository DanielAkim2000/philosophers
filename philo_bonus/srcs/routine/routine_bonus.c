/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:54:12 by demane            #+#    #+#             */
/*   Updated: 2026/02/15 14:23:56 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:54:12 by demane            #+#    #+#             */
/*   Updated: 2026/02/15 14:30:00 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine_bonus.h"

static void	ft_routine_gap_bonus(t_philo *p)
{
	if (p->rules->nb_philo % 2 == 0)
	{
		if (p->id % 2 != 0)
			usleep(1000);
	}
	else
	{
		if (p->id == p->rules->nb_philo)
			usleep(p->rules->t_eat * 1000);
		else if (p->id % 2 != 0)
			usleep(1000);
	}
}

static void	ft_process_routine_bonus(t_philo *p)
{
	/* IMPROVED: Handle single philosopher case early */
	if (p->rules->nb_philo == 1)
	{
		sem_wait(p->rules->forks);
		ft_safe_print_bonus(p, "has taken a fork");
		/* Wait for death - watcher will handle it */
		while (1)
			usleep(1000);
	}
	while (1)
	{
		sem_wait(p->rules->death);
		if (p->rules->is_dead)
		{
			sem_post(p->rules->death);
			break ;
		}
		sem_post(p->rules->death);
		sem_wait(p->rules->meal);
		if (p->is_full)
		{
			sem_post(p->rules->meal);
			break ;
		}
		sem_post(p->rules->meal);
		ft_take_forks_bonus(p);
		ft_eat_bonus(p);
		ft_put_forks_bonus(p);
		ft_sleep_philo_bonus(p);
		ft_think_bonus(p);
	}
	exit(0);
}

void	*ft_routine_bonus(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	ft_routine_gap_bonus(p);
	ft_process_routine_bonus(p);
	return (NULL);
}
