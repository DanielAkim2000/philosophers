/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:54:15 by demane            #+#    #+#             */
/*   Updated: 2026/02/13 19:50:51 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

static int	ft_start_simulation_bonus(t_philo *philos)
{
	int			i;
	pthread_t	thread;

	i = 0;
	while (i < philos[0].rules->nb_philo)
	{
		philos[i].last_meal = philos->rules->start_time;
		philos[i].pid = fork();
		if (philos[i].pid == -1)
			return (i);
		if (philos[i].pid == 0)
		{
			pthread_create(&thread, NULL, ft_watcher, &philos[i]);
			ft_routine_bonus(&philos[i]);
			exit(0);
		}
	}
	return (0);
}

static void	ft_wait_all_philos(t_philo *p)
{
	pid_t	*pids;
	int		i;
	int		status;
	int		j;

	status = 0;
	pids = (pid_t *)malloc(sizeof(p->rules->nb_philo));
	if (!pids)
		return ;
	i = 0;
	while (i < p->rules->nb_meals && status == 0)
	{
		pids[i++] = wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		else
			status = -1;
	}
	if (i == p->rules->nb_philo)
		return ;
	i = -1;
	while (++i < p->rules->nb_philo)
		if (!ft_is_include(pids, p[i].pid))
			kill(p[i].pid);
}

static void	ft_wait_all_philos_err(int n, t_philo *p)
{
	int	i;

	i = -1;
	while (++i < n)
		kill(p[i].pid);
}

void	ft_clean_bonus(t_rules *r, t_philo *p)
{
	sem_close(r->print);
	sem_close(r->death);
	sem_close(r->meal);
	sem_close(r->forks);
	sem_unlink(r->print);
	sem_unlink(r->death);
	sem_unlink(r->meal);
	sem_unlink(r->forks);
	ft_free((void **)&r);
	ft_free((void **)&p);
}

int	main(int ac, char **av)
{
	t_rules	*rules;
	t_philo	*philos;
	int		n;

	rules = ft_parse_arg(ac, av);
	if (!rules)
		return (1);
	if (ft_init_rules_sem(rules))
		return (ft_free((void **)&rules), 1);
	philos = ft_init_philos_bonus(rules);
	if (!philos)
		return (ft_free_bonus((void **)&rules), 1);
	rules->start_time = ft_gettime_bonus();
	n = ft_start_simulation_bonus(philos);
	if (!n)
		ft_wait_all_philos(philos);
	else
		ft_wait_all_philos_err(n, philos);
	ft_clean_bonus(rules, philos);
}
