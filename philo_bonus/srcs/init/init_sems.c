/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sems.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:20:25 by demane            #+#    #+#             */
/*   Updated: 2026/02/20 23:03:36 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/init_bonus.h"
#include "../../includes/utils_bonus.h"

void	ft_init_sems(t_rules *rules)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	rules->forks = sem_open("/forks", O_CREAT, 0644, rules->nb_philo);
	rules->print = sem_open("/print", O_CREAT, 0644, 1);
	if (rules->forks == SEM_FAILED || rules->print == SEM_FAILED)
		ft_fatal("sem_open failed");
}
