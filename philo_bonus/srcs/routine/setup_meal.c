/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_meal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:20:25 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 05:52:46 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine_bonus.h"

void	ft_setup_meal_name(t_philo *p)
{
	p->meal_name[0] = '/';
	p->meal_name[1] = 'm';
	p->meal_name[2] = 'e';
	p->meal_name[3] = 'a';
	p->meal_name[4] = 'l';
	p->meal_name[5] = '_';
	p->meal_name[6] = '0' + (p->id / 100);
	p->meal_name[7] = '0' + ((p->id / 10) % 10);
	p->meal_name[8] = '0' + (p->id % 10);
	p->meal_name[9] = '\0';
}
