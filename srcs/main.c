/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:07:42 by demane            #+#    #+#             */
/*   Updated: 2026/02/06 18:17:27 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	ft_print_rules(t_rules *rule)
{
	printf("nb_philo = %d\ntime_to_die = %ld\n, time_to_eat = %ld\n\
time_to_sleep = %ld\nnumber_of_times_each_philosopher_must_eat = %d\n"\
, rule->nb_philo, rule->t_die, rule->t_eat, rule->t_sleep, rule->nb_meals);
}

int	main(int ac, char **av)
{
	t_rules	*rules;
	t_philo	*philos;

	rules = ft_parse_arg(ac, av);
	if (!rules)
		return (1);
	ft_print_rules(rules);
	ft_init_rules_mutex(rules);
	ft_init_rules_mutex(rules);
}
