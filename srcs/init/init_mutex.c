/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:06:47 by demane            #+#    #+#             */
/*   Updated: 2026/02/08 02:10:19 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/init.h"

int	ft_init_rules_mutex(t_rules *rules)
{
	if (pthread_mutex_init(&rules->print, NULL))
		return (1);
	if (pthread_mutex_init(&rules->death, NULL))
		return (1);
	if (pthread_mutex_init(&rules->meal, NULL))
		return (1);
	return (0);
}


pthread_mutex_t	*ft_init_forks(t_rules *rules)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* rules->nb_philo);
	if (!forks)
		return (NULL);
	while (i < rules->nb_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (ft_free((void **)&forks), NULL);
		i++;
	}
	return (forks);
}

t_philo	*ft_init_philos(t_rules *rules, pthread_mutex_t *forks)
{
	int		i;
	t_philo	*philos;
	int		right_index;

	i = -1;
	philos = (t_philo *)malloc(sizeof(t_philo) * rules->nb_philo);
	if (!philos)
		return (NULL);
	while (++i < rules->nb_philo)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].rules = rules;
		philos[i].left_fork = &forks[i];
		right_index = (i + 1) % rules->nb_philo;
		philos[i].right_fork = &forks[right_index];
		philos[i].last_meal = rules->start_time;
		philos[i].is_full = 0;
	}
	return (philos);
}
