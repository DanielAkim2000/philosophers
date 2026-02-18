/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:54:12 by demane            #+#    #+#             */
/*   Updated: 2026/02/18 17:34:58 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine_bonus.h"

static void	ft_cleanup_child(t_philo *p)
{
	sem_close(p->rules->print);
	sem_close(p->rules->death);
	sem_close(p->rules->meal);
	sem_close(p->rules->forks);
}

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
	if (p->rules->nb_philo == 1)
	{
		sem_wait(p->rules->forks);
		ft_safe_print_bonus(p, "has taken a fork");
		while (1)
			usleep(1000);
	}
	while (1)
	{
		sem_wait(p->rules->meal);
		if (p->is_full || p->should_exit)
		{
			sem_post(p->rules->meal);
			return ;
		}
		sem_post(p->rules->meal);
		ft_take_forks_bonus(p);
		sem_wait(p->rules->meal);
		if (p->should_exit)
		{
			sem_post(p->rules->meal);
			ft_put_forks_bonus(p);
			return ;
		}
		sem_post(p->rules->meal);
		ft_eat_bonus(p);
		ft_put_forks_bonus(p);
		ft_sleep_philo_bonus(p);
		ft_think_bonus(p);
	}
}

int	ft_routine_bonus(void *arg)
{
	t_philo		*p;
	pthread_t	thread;
	void		*watcher_ret;

	p = (t_philo *)arg;
	p->should_exit = 0;
	pthread_create(&thread, NULL, ft_watcher, p);
	ft_routine_gap_bonus(p);
	ft_process_routine_bonus(p);
	pthread_join(thread, &watcher_ret);
	ft_cleanup_child(p);
	if (watcher_ret == (void *)1)
		return (1);
	return (0);
}
