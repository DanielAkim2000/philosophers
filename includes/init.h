/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:12:26 by demane            #+#    #+#             */
/*   Updated: 2026/02/06 16:25:30 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "base.h"

int				ft_init_rules_mutex(t_rules *rules);
pthread_mutex_t	*ft_init_forks(t_rules *rules);
t_philo			*ft_init_philos(t_rules *rules, pthread_mutex_t *forks);

#endif
