/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 12:47:06 by demane            #+#    #+#             */
/*   Updated: 2026/02/13 13:08:46 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/watcher.h"

void	*ft_watcher(void *arg)
{
	t_philo	*p;
	long	current_time;

	p = (t_philo *)arg;
	while (1)
	{
		current_time = ft_gettime_bonus();
		if (p->is_full)
			exit(0);
		if (current_time - p->last_meal <= p->rules->t_die)
			exit(1);
		usleep(1000);
	}
}
