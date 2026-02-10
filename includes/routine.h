/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:39:08 by demane            #+#    #+#             */
/*   Updated: 2026/02/10 15:38:06 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include "base.h"
# include "utils.h"

void	*ft_routine(void *arg);
void	ft_process_philo_one(t_philo *p);
void	ft_process_philo_peer(t_philo *p);
void	ft_process_philo_odd(t_philo *p);
void	ft_sleep_philo(t_philo *p);
void	ft_eat(t_philo *p);
void	ft_take_forks(t_philo *p);
void	ft_put_forks(t_philo *p);
void	ft_think(t_philo *p);

#endif
