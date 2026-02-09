/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:44:40 by demane            #+#    #+#             */
/*   Updated: 2026/02/08 13:39:48 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

long	ft_gettime(void)
{
	t_timeval	tv;
	long		time;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void	ft_usleep(long t_ms, t_philo *p)
{
	long	start;

	start = ft_gettime();
	while (1)
	{
		//pthread_mutex_lock(&p->rules->meal);
		if (p->rules->is_dead || p->is_full)
		{
			//pthread_mutex_unlock(&p->rules->meal);
			break ;
		}
		//pthread_mutex_unlock(&p->rules->meal);

		if (ft_gettime() - start >= t_ms)
			break ;
		usleep(50);
	}
}

