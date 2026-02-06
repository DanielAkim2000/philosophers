/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:06:47 by demane            #+#    #+#             */
/*   Updated: 2026/02/06 18:16:22 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/init.h"

int	ft_init_rules_mutex(t_rules *rules)
{
	if (pthread_mutex_init(&rules->print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&rules->death, NULL) != 0)
		return (1);
	return (0);
}


pthread_mutex_t *ft_init_forks(t_rules *rules);
