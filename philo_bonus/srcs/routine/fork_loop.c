/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:20:25 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 05:26:28 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine_bonus.h"

void	ft_fork_loop(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		rules->pids[i] = fork();
		if (rules->pids[i] == 0)
			ft_child_process(rules, i);
		i++;
		usleep(1000);
	}
}
