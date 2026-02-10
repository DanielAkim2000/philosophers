/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:39:08 by demane            #+#    #+#             */
/*   Updated: 2026/02/09 13:50:53 by demane           ###   ########.fr       */
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

#endif