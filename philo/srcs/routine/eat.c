/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:27:59 by demane            #+#    #+#             */
/*   Updated: 2026/02/16 18:57:53 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine.h"

void	ft_eat(t_philo *p)
{
	ft_safe_print(p, "is eating");
	pthread_mutex_lock(&p->rules->meal);
	p->last_meal = ft_gettime();
	p->meals_eaten++;
	if (p->rules->nb_meals > 0 && p->meals_eaten >= p->rules->nb_meals)
		p->is_full = 1;
	pthread_mutex_unlock(&p->rules->meal);
	ft_usleep(p->rules->t_eat, p);
}
