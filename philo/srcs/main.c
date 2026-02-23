/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:07:42 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 05:26:27 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	ft_start_simulation(t_philo *philos)
{
	int		i;
	t_rules	*r;

	i = 0;
	r = philos->rules;
	while (i < philos[0].rules->nb_philo)
	{
		philos[i].last_meal = r->start_time;
		if (pthread_create(&philos[i].thread, NULL, ft_routine, &philos[i]))
			return (i);
		i++;
	}
	if (pthread_create(&r->monitor, NULL, ft_routine_monitor, philos))
		return (-1);
	return (0);
}

static void	ft_join_threads(t_rules *rules, t_philo *philos, int n)
{
	int	i;

	if (n == -1)
	{
		pthread_join(rules->monitor, NULL);
		return ;
	}
	i = -1;
	while (++i < n)
		pthread_join(philos[i].thread, NULL);
	if (n == rules->nb_philo)
		pthread_join(rules->monitor, NULL);
}

static void	ft_destroy(t_rules *rules, pthread_mutex_t *forks)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&rules->print);
	pthread_mutex_destroy(&rules->meal);
	pthread_mutex_destroy(&rules->death);
	if (forks)
	{
		while (++i < rules->nb_philo)
			pthread_mutex_destroy(&forks[i]);
	}
}

static void	ft_clean(t_rules *rules, pthread_mutex_t *forks, t_philo *p)
{
	ft_destroy(rules, forks);
	ft_free((void **)&forks);
	ft_free((void **)&p);
	ft_free((void **)&rules);
}

int	main(int ac, char **av)
{
	t_rules			*rules;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				n;

	rules = ft_parse_arg(ac, av);
	if (!rules)
		return (1);
	if (ft_init_rules_mutex(rules))
		return (ft_free((void **)&rules), 1);
	forks = ft_init_forks(rules);
	if (!forks)
		return (ft_destroy(rules, NULL), ft_free((void **)&rules), 1);
	philos = ft_init_philos(rules, forks);
	if (!philos)
		return (ft_destroy(rules, forks), ft_free((void **)&rules),
			ft_free((void **)&forks), 1);
	rules->start_time = ft_gettime();
	n = ft_start_simulation(philos);
	if (!n)
		ft_join_threads(rules, philos, rules->nb_philo);
	else
		ft_join_threads(rules, philos, n);
	ft_clean(rules, forks, philos);
}
