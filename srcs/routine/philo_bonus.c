/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:57:19 by demane            #+#    #+#             */
/*   Updated: 2026/02/13 19:49:09 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine_bonus.h"

void	ft_process_philo_one(t_philo *p)
{
	sem_wait(p->rules->forks);
	ft_safe_print_bonus(p, "has taken a fork");
	ft_usleep_bonus(p->rules->t_die, p);
	sem_post(p->rules->forks);
}

void	ft_process_philo_bonus(t_philo *p)
{
	sem_wait(p->rules->forks);
	ft_safe_print_bonus(p, "has taken a fork");
	sem_wait(p->rules->forks);
	ft_safe_print_bonus(p, "has taken a fork");
}
