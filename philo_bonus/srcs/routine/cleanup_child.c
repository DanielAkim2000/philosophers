/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:20:25 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 00:42:01 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine_bonus.h"

void	ft_cleanup_child(t_philo *p)
{
	sem_close(p->meal_sem);
	sem_unlink(p->meal_name);
	sem_close(p->dead_sem);
	sem_unlink(p->dead_name);
	sem_close(p->rules->forks);
	sem_close(p->rules->print);
}
