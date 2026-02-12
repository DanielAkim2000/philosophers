/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:55:35 by demane            #+#    #+#             */
/*   Updated: 2026/02/12 18:06:43 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine_bonus.h"

void	ft_take_forks_bonus(t_philo *p)
{
	if (p->rules->nb_philo == 1)
		ft_process_philo_one_bonus(p);
	else
		ft_process_philo_bonus(p);
}

void	ft_put_forks_bonus(t_philo *p)
{
	sem_post(p->rules->forks);
	sem_post(p->rules->forks);
}
