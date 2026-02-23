/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:15:19 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 05:26:27 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_BONUS_H
# define ROUTINE_BONUS_H

# include "base_bonus.h"

void	*ft_routine(void *arg);
long	ft_get_think_time(t_philo *p);
void	ft_child_process(t_rules *rules, int i);
void	ft_print_action(t_philo *p, char *msg);
void	ft_setup_meal_name(t_philo *p);
void	ft_eat_routine(t_philo *p);
void	ft_sleep_think(t_philo *p);
void	ft_cleanup_child(t_philo *p);
void	ft_cleanup_parent(t_rules *rules);
void	ft_fork_loop(t_rules *rules);
void	ft_wait_loop(t_rules *rules);
void	ft_kill_loop(t_rules *rules);

#endif
