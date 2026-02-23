/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:20:25 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 05:53:30 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/monitor_bonus.h"
#include "../../includes/routine_bonus.h"
#include "../../includes/utils_bonus.h"

static void	ft_setup_dead_name(t_philo *p)
{
	p->dead_name[0] = '/';
	p->dead_name[1] = 'd';
	p->dead_name[2] = 'e';
	p->dead_name[3] = 'a';
	p->dead_name[4] = 'd';
	p->dead_name[5] = '_';
	p->meal_name[6] = '0' + (p->id / 100);
	p->meal_name[7] = '0' + ((p->id / 10) % 10);
	p->meal_name[8] = '0' + (p->id % 10);
	p->meal_name[9] = '\0';
}

static void	ft_init_child(t_philo *p, t_rules *rules, int i)
{
	p->id = i + 1;
	p->meals_eaten = 0;
	p->rules = rules;
	p->last_meal = ft_get_time();
	p->is_dead = 0;
	ft_setup_meal_name(p);
	sem_unlink(p->meal_name);
	p->meal_sem = sem_open(p->meal_name, O_CREAT, 0644, 1);
	ft_setup_dead_name(p);
	sem_unlink(p->dead_name);
	p->dead_sem = sem_open(p->dead_name, O_CREAT, 0644, 0);
}

static void	ft_run_child(t_philo *p)
{
	int	code;

	pthread_create(&p->monitor, NULL, ft_monitor, p);
	pthread_create(&p->routine, NULL, ft_routine, p);
	sem_wait(p->dead_sem);
	sem_wait(p->meal_sem);
	code = p->is_dead;
	sem_post(p->meal_sem);
	sem_post(p->rules->forks);
	sem_post(p->rules->forks);
	pthread_join(p->routine, NULL);
	pthread_join(p->monitor, NULL);
	ft_cleanup_child(p);
	free(p->rules->pids);
	exit(code);
}

void	ft_child_process(t_rules *rules, int i)
{
	t_philo	p;

	ft_init_child(&p, rules, i);
	if (p.meal_sem == SEM_FAILED || p.dead_sem == SEM_FAILED)
	{
		ft_cleanup_child(&p);
		free(rules->pids);
		exit(1);
	}
	ft_run_child(&p);
}
