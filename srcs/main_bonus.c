/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:54:15 by demane            #+#    #+#             */
/*   Updated: 2026/02/10 18:34:51 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

int	main(int ac, char **av)
{
	t_rules	*rules;
	t_philo	*philos;

	rules = ft_parse_arg(ac, av);
	if (!rules)
		return (1);
	if (ft_init_rules_sem(rules))
		return (ft_free((void **)&rules), 1);
	philos = ft_init_philos_bonus(rules);
	if (!philos)
		return (ft_free_bonus((void **)&rules), 1);
	rules->start_time = ft_gettime_bonus();
}
