/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:20:25 by demane            #+#    #+#             */
/*   Updated: 2026/02/20 22:44:15 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/base_bonus.h"

void	ft_kill_loop(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		kill(rules->pids[i], SIGKILL);
		i++;
	}
}
