/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:21:44 by demane            #+#    #+#             */
/*   Updated: 2026/02/10 18:22:39 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "base_bonus.h"

void	ft_free_bonus(void **addr_ptr);
long	ft_gettime_bonus(void);
void	ft_usleep_bonus(long t_ms, t_philo *p);
void	ft_safe_print_bonus(t_philo *p, char *msg);

#endif
