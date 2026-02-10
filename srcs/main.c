/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:07:42 by demane            #+#    #+#             */
/*   Updated: 2026/02/09 13:24:01 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	ft_start_simulation(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].rules->nb_philo)
	{
		philos[i].last_meal = philos[i].rules->start_time;
		if (pthread_create(&philos[i].thread, NULL,
				ft_routine, &philos[i]))
			return (1);
		i++;
	}
	return (0);
}


int	main(int ac, char **av)
{
	t_rules			*rules;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	rules = ft_parse_arg(ac, av);
	if (!rules)
		return (1);
	if (ft_init_rules_mutex(rules))
		return (1);
	forks = ft_init_forks(rules);
	if (!forks)
		return (1);
	philos = ft_init_philos(rules, forks);
	if (!philos)
		return (1);
	rules->start_time = ft_gettime();
	ft_start_simulation(philos);
	ft_monitor(philos);
	int i = 0;
	while (i < rules->nb_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&rules->print);
	pthread_mutex_destroy(&rules->meal);
	pthread_mutex_destroy(&rules->death);
	for (i = 0; i < rules->nb_philo; i++)
		pthread_mutex_destroy(&forks[i]);
	ft_free((void **)&forks);
	ft_free((void **)&philos);
	ft_free((void **)&rules);
}
