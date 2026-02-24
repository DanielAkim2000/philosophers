/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:15:19 by demane            #+#    #+#             */
/*   Updated: 2026/02/24 00:07:42 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "base_bonus.h"

int		ft_strlen(char *s);
long	ft_get_time(void);
void	ft_usleep(long ms, t_philo *p);
void	ft_fatal(char *msg);
void	ft_putnbr_fd(long n, int fd);

#endif
