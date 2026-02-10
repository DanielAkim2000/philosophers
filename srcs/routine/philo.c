/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:52:31 by demane            #+#    #+#             */
/*   Updated: 2026/02/09 13:49:44 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine.h"

void	ft_process_philo_one(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	ft_safe_print(p, "has taken a fork");
	ft_usleep(p->rules->t_die, p);
	pthread_mutex_unlock(p->left_fork);
}

void	ft_process_philo_peer(t_philo *p)
{
	pthread_mutex_lock(p->left_fork);
	ft_safe_print(p, "has taken a fork");
	pthread_mutex_lock(p->right_fork);
	ft_safe_print(p, "has taken a fork");
}

void	ft_process_philo_odd(t_philo *p)
{
	pthread_mutex_lock(p->right_fork);
	ft_safe_print(p, "has taken a fork");
	pthread_mutex_lock(p->left_fork);
	ft_safe_print(p, "has taken a fork");
}

void	ft_sleep_philo(t_philo *p)
{
	pthread_mutex_lock(&p->rules->death);
	if (p->rules->is_dead)
	{
		pthread_mutex_unlock(&p->rules->death);
		return ;
	}
	pthread_mutex_unlock(&p->rules->death);
	ft_safe_print(p, "is sleeping");
	ft_usleep(p->rules->t_sleep, p);
}
