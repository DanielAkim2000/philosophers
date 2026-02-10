/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:25:57 by demane            #+#    #+#             */
/*   Updated: 2026/02/10 15:46:38 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	ft_free(void **addr_ptr)
{
	if (addr_ptr && *addr_ptr)
	{
		free(*addr_ptr);
		*addr_ptr = NULL;
	}
}

void	ft_safe_print(t_philo *p, char *msg)
{
	long	time;

	pthread_mutex_lock(&p->rules->print);
	pthread_mutex_lock(&p->rules->death);
	if (!p->rules->is_dead)
	{
		time = ft_gettime() - p->rules->start_time;
		printf("%ld %d %s\n", time, p->id, msg);
	}
	pthread_mutex_unlock(&p->rules->death);
	pthread_mutex_unlock(&p->rules->print);
}
