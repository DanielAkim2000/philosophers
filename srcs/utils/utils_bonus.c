/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:26:26 by demane            #+#    #+#             */
/*   Updated: 2026/02/10 18:32:20 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils_bonus.h"

void	ft_free_bonus(void **addr_ptr)
{
	if (addr_ptr && *addr_ptr)
	{
		free(*addr_ptr);
		*addr_ptr = NULL;
	}
}

void	ft_safe_print_bonus(t_philo *p, char *msg)
{
	long	time;

	sem_wait(&p->rules->print);
	sem_wait(&p->rules->death);
	if (!p->rules->is_dead)
	{
		time = ft_gettime() - p->rules->start_time;
		printf("%ld %d %s\n", time, p->id, msg);
	}
	sem_post(&p->rules->death);
	sem_post(&p->rules->print);
}
