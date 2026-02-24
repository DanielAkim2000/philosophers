/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:34:05 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 22:37:22 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "base.h"

void	ft_free(void **addr_ptr);
long	ft_gettime(void);
void	ft_usleep(long t_ms, t_philo *p);
void	ft_safe_print(t_philo *p, char *msg);
void	ft_putnbr_fd(long n, int fd);

#endif
