/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:33:19 by demane            #+#    #+#             */
/*   Updated: 2026/02/15 14:23:38 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine_bonus.h"

void	ft_eat_bonus(t_philo *p)
{
	/* Print eating message */
	ft_safe_print_bonus(p, "is eating");
	/* IMPROVED: Update last_meal BEFORE eating to avoid death during eating */
	sem_wait(p->rules->meal);
	p->last_meal = ft_gettime_bonus();
	p->meals_eaten++;
	if (p->rules->nb_meals > 0 && p->meals_eaten >= p->rules->nb_meals)
		p->is_full = 1;
	sem_post(p->rules->meal);
	/* Sleep for eating time */
	ft_usleep_bonus(p->rules->t_eat, p);
}
