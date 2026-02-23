/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:20:25 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 05:26:28 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine_bonus.h"

long	ft_get_think_time(t_philo *p)
{
	long	t;

	if (p->rules->nb_philo % 2 == 1)
		t = p->rules->t_eat * 2 - p->rules->t_sleep;
	else
		t = p->rules->t_eat - p->rules->t_sleep;
	if (t < 0)
		t = 0;
	return (t);
}
