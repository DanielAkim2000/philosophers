/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:25:53 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 05:26:27 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine.h"

static void	ft_lock_left_right(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	ft_safe_print(p, "has taken a fork");
	pthread_mutex_lock(p->right_fork);
	ft_safe_print(p, "has taken a fork");
}

static void	ft_lock_right_left(t_philo *p)
{
	pthread_mutex_lock(p->right_fork);
	ft_safe_print(p, "has taken a fork");
	pthread_mutex_lock(p->left_fork);
	ft_safe_print(p, "has taken a fork");
}

void	ft_take_forks(t_philo *p)
{
	if (p->rules->nb_philo == 1)
	{
		ft_process_philo_one(p);
		return ;
	}
	if (p->id % 2 == 0)
		ft_lock_left_right(p);
	else
		ft_lock_right_left(p);
}

void	ft_put_forks(t_philo *p)
{
	pthread_mutex_unlock(p->left_fork);
	if (p->right_fork != p->left_fork)
		pthread_mutex_unlock(p->right_fork);
}
