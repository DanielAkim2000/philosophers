/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:20:25 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 22:37:22 by demane           ###   ########.fr       */
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
	ft_putnbr_fd(ft_get_time() - p->rules->start_time, 1);
	write(1, " ", 1);
	ft_putnbr_fd((long)p->id, 1);
	write(1, " ", 1);
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	sem_post(p->rules->print);
}
