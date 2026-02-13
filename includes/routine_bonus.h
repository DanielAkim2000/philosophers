/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:58:29 by demane            #+#    #+#             */
/*   Updated: 2026/02/13 19:48:33 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_BONUS_H
# define ROUTINE_BONUS_H

# include "base_bonus.h"
# include "utils_bonus.h"

void	*ft_routine_bonus(void *arg);
void	ft_take_forks_bonus(t_philo *p);
void	ft_process_philo_one_bonus(t_philo *p);
void	ft_process_philo_bonus(t_philo *p);
void	ft_eat_bonus(t_philo *p);
void	ft_put_forks_bonus(t_philo *p);
void	ft_think_bonus(t_philo *p);
void	ft_sleep_philo_bonus(t_philo *p);

#endif
