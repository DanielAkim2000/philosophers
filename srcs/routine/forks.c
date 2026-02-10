/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:25:53 by demane            #+#    #+#             */
/*   Updated: 2026/02/10 15:28:12 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine.h"

void	ft_take_forks(t_philo *p)
{
	if (p->rules->nb_philo == 1)
		ft_process_philo_one(p);
	else if (p->id % 2 == 0)
		ft_process_philo_peer(p);
	else
		ft_process_philo_odd(p);
}

void	ft_put_forks(t_philo *p)
{
	pthread_mutex_unlock(p->left_fork);
	if (p->right_fork != p->left_fork)
		pthread_mutex_unlock(p->right_fork);
}
