/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:20:25 by demane            #+#    #+#             */
/*   Updated: 2026/02/24 00:07:42 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine_bonus.h"
#include "../../includes/utils_bonus.h"

void	ft_sleep_think(t_philo *p)
{
	long	time_think;

	ft_print_action(p, "is sleeping");
	ft_usleep(p->rules->t_sleep, p);
	ft_print_action(p, "is thinking");
	time_think = ft_get_think_time(p);
	ft_usleep(time_think, p);
}
