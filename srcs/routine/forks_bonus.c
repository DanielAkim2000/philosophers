/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:55:35 by demane            #+#    #+#             */
/*   Updated: 2026/02/15 14:38:07 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine_bonus.h"

void	ft_take_forks_bonus(t_philo *p)
{
	/* SIMPLIFIED: Single philosopher case now handled in routine_bonus.c */
	ft_process_philo_bonus(p);
}

void	ft_put_forks_bonus(t_philo *p)
{
	sem_post(p->rules->forks);
	sem_post(p->rules->forks);
}
