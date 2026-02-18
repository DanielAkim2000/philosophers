/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:54:15 by demane            #+#    #+#             */
/*   Updated: 2026/02/18 11:45:49 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

int	ft_is_include(pid_t *pids, pid_t pid, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (pids[i] == pid)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_start_simulation_bonus(t_philo *philos)
{
	int	i;
	int	status;

	i = -1;
	while (++i < philos[0].rules->nb_philo)
	{
		philos[i].last_meal = philos->rules->start_time;
		philos[i].pid = fork();
		if (philos[i].pid == -1)
			return (i);
		if (philos[i].pid == 0)
		{
			status = ft_routine_bonus(&philos[i]);
			ft_free_bonus((void **)&philos[i].rules);
			ft_free_bonus((void **)&philos);
			exit(status);
		}
	}
	return (0);
}
static int	ft_wait_all_philos(t_philo *p)
{
	int	status;
	int	i;
	int	finished;

	finished = 0;
	while (finished < p->rules->nb_philo)
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) != 0)
			{
				i = -1;
				while (++i < p->rules->nb_philo)
					kill(p[i].pid, SIGKILL);
				while (wait(&status) > 0)
					;
				return (0);
			}
		}
		finished++;
	}
	return (0);
}

static void	ft_wait_all_philos_err(int n, t_philo *p)
{
	int	i;

	i = -1;
	while (++i < n)
		kill(p[i].pid, SIGKILL);
}

void	ft_clean_bonus(t_rules *r, t_philo *p)
{
	sem_close(r->print);
	sem_close(r->death);
	sem_close(r->meal);
	sem_close(r->forks);
	sem_unlink("/print");
	sem_unlink("/dead");
	sem_unlink("/meal");
	sem_unlink("/forks");
	ft_free_bonus((void **)&r);
	ft_free_bonus((void **)&p);
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
		return (ft_free_bonus((void **)&rules), 1);
	philos = ft_init_philos_bonus(rules);
	if (!philos)
		return (ft_free_bonus((void **)&rules), 1);
	rules->start_time = ft_gettime_bonus();
	n = ft_start_simulation_bonus(philos);
	if (!n)
	{
		if (ft_wait_all_philos(philos))
			ft_wait_all_philos_err(rules->nb_philo, philos);
	}
	else
		ft_wait_all_philos_err(n, philos);
	ft_clean_bonus(rules, philos);
	return (0);
}
