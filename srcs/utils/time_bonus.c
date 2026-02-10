/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:27:44 by demane            #+#    #+#             */
/*   Updated: 2026/02/10 18:31:24 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_bonus.h"

long	ft_gettime_bonus(void)
{
	t_timeval	tv;
	long		time;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}


void	ft_usleep_bonus(long t_ms, t_philo *p)
{
	long	start;

	start = ft_gettime();
	while (1)
	{
		sem_wait(&p->rules->death);
		if (p->rules->is_dead)
		{
			sem_post(&p->rules->death);
			return ;
		}
		sem_post(&p->rules->death);
		sem_wait(&p->rules->meal);
		if (p->is_full)
		{
			sem_post(&p->rules->meal);
			return ;
		}
		sem_post(&p->rules->meal);
		if (ft_gettime() - start >= t_ms)
			break ;
		usleep(1000);
	}
}
