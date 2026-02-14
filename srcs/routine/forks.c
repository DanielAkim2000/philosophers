/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:25:53 by demane            #+#    #+#             */
/*   Updated: 2026/02/14 01:00:50 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine.h"

void	ft_take_forks(t_philo *p)
{
	if (p->rules->nb_philo == 1)
	{
		ft_process_philo_one(p);
		return ;
	}
	if (p->rules->nb_philo % 2 != 0 && p->id == p->rules->nb_philo)
	{
		pthread_mutex_lock(p->left_fork);
		ft_safe_print(p, "has taken a fork");
		pthread_mutex_lock(p->right_fork);
		ft_safe_print(p, "has taken a fork");
		return ;
	}
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(p->left_fork);
		ft_safe_print(p, "has taken a fork");
		pthread_mutex_lock(p->right_fork);
		ft_safe_print(p, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(p->right_fork);
		ft_safe_print(p, "has taken a fork");
		pthread_mutex_lock(p->left_fork);
		ft_safe_print(p, "has taken a fork");
	}
}

void	ft_put_forks(t_philo *p)
{
	pthread_mutex_unlock(p->left_fork);
	if (p->right_fork != p->left_fork)
		pthread_mutex_unlock(p->right_fork);
}
