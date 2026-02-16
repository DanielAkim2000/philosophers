/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:20:51 by demane            #+#    #+#             */
/*   Updated: 2026/02/16 18:03:21 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/init_bonus.h"

static void	ft_clear_sem(t_rules *rules)
{
	sem_close(rules->print);
	sem_close(rules->death);
	sem_close(rules->meal);
	sem_unlink("/print");
	sem_unlink("/dead");
	sem_unlink("/meal");
}

int	ft_init_rules_sem(t_rules *rules)
{
	sem_unlink("/print");
	sem_unlink("/dead");
	sem_unlink("/meal");
	sem_unlink("/forks");
	rules->print = sem_open("/print", O_CREAT, 0644, 1);
	if (rules->print == SEM_FAILED)
		return (1);
	rules->death = sem_open("/dead", O_CREAT, 0644, 1);
	if (rules->death == SEM_FAILED)
	{
		sem_close(rules->print);
		sem_unlink("/print");
		return (1);
	}
	rules->meal = sem_open("/meal", O_CREAT, 0644, 1);
	if (rules->meal == SEM_FAILED)
	{
		sem_close(rules->print);
		sem_close(rules->death);
		sem_unlink("/print");
		sem_unlink("/dead");
		return (1);
	}
	rules->forks = sem_open("/forks", O_CREAT, 0644, rules->nb_philo);
	if (rules->forks == SEM_FAILED)
		return (ft_clear_sem(rules), 1);
	return (0);
}

t_philo	*ft_init_philos_bonus(t_rules *rules)
{
	int		i;
	t_philo	*philos;

	i = -1;
	philos = (t_philo *)malloc(sizeof(t_philo) * rules->nb_philo);
	if (!philos)
		return (NULL);
	while (++i < rules->nb_philo)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].rules = rules;
		philos[i].is_full = 0;
	}
	return (philos);
}
