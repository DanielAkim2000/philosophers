/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:32:14 by demane            #+#    #+#             */
/*   Updated: 2026/02/09 13:12:19 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

t_rules	*ft_parse_arg(int ac, char **av)
{
	t_rules	*rules;

	if (ac != 6 && ac != 5)
		return (NULL);
	rules = (t_rules *)malloc(sizeof(t_rules) * 1);
	if (!rules)
		return (NULL);
	rules->nb_philo = ft_atoi(av[1]);
	if (rules->nb_philo < 0)
		return (ft_free((void **)&rules), NULL);
	rules->t_die = ft_atol(av[2]);
	if (rules->t_die < 0)
		return (ft_free((void **)&rules), NULL);
	rules->t_eat = ft_atol(av[3]);
	if (rules->t_eat < 0)
		return (ft_free((void **)&rules), NULL);
	rules->t_sleep = ft_atol(av[4]);
	if (rules->t_sleep < 0)
		return (ft_free((void **)&rules), NULL);
	if (ac == 6)
	{
		rules->nb_meals = ft_atoi(av[5]);
		if (rules->nb_meals < 0)
			return (ft_free((void **)&rules), NULL);
	}
	else
		rules->nb_meals = -1;
	return (rules);
}
