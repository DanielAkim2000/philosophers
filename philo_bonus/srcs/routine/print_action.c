/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:20:25 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 16:03:56 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine_bonus.h"
#include "../../includes/utils_bonus.h"

void	ft_print_action(t_philo *p, char *msg)
{
	sem_wait(p->meal_sem);
	if (p->is_dead)
	{
		sem_post(p->meal_sem);
		return ;
	}
	sem_post(p->meal_sem);
	sem_wait(p->rules->print);
	printf("%ld %d %s\n", ft_get_time() - p->rules->start_time, p->id, msg);
	fflush(stdout);
	sem_post(p->rules->print);
}
