/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:20:25 by demane            #+#    #+#             */
/*   Updated: 2026/02/20 22:44:15 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine_bonus.h"
#include "../../includes/utils_bonus.h"

void	ft_sleep_think(t_philo *p)
{
	ft_print_action(p, "is sleeping");
	ft_sleep(p->rules->t_sleep);
	ft_print_action(p, "is thinking");
	ft_sleep(ft_get_think_time(p));
}
