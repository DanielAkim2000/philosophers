/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:32:14 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 23:02:30 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static int	fill_rules(t_rules *rules, int ac, char **av)
{
	rules->nb_philo = ft_atoi(av[1]);
	if (rules->nb_philo <= 0)
		return (1);
	rules->t_die = ft_atol(av[2]);
	if (rules->t_die < 0)
		return (1);
	rules->t_eat = ft_atol(av[3]);
	if (rules->t_eat < 0)
		return (1);
	rules->t_sleep = ft_atol(av[4]);
	if (rules->t_sleep < 0)
		return (1);
	if (ac == 6)
	{
		rules->nb_meals = ft_atoi(av[5]);
		if (rules->nb_meals < 0)
			return (1);
	}
	else
		rules->nb_meals = -1;
	rules->is_dead = 0;
	return (0);
}

t_rules	*ft_parse_arg(int ac, char **av)
{
	t_rules	*rules;

	if (ac != 5 && ac != 6)
		return (NULL);
	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (NULL);
	if (fill_rules(rules, ac, av))
	{
		ft_free((void **)&rules);
		return (NULL);
	}
	return (rules);
}
