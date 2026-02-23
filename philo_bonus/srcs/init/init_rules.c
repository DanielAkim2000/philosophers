/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:20:25 by demane            #+#    #+#             */
/*   Updated: 2026/02/20 22:44:15 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/init_bonus.h"
#include "../../includes/parsing_bonus.h"

int	ft_init_rules(t_rules *rules, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (0);
	rules->nb_philo = ft_atoi(av[1]);
	rules->t_die = ft_atoi(av[2]);
	rules->t_eat = ft_atoi(av[3]);
	rules->t_sleep = ft_atoi(av[4]);
	rules->nb_meals = -1;
	if (ac == 6)
		rules->nb_meals = ft_atoi(av[5]);
	return (rules->nb_philo > 0);
}
