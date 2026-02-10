/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:57:10 by demane            #+#    #+#             */
/*   Updated: 2026/02/10 18:59:43 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_BONUS_H
# define INIT_BONUS_H

# include "base_bonus.h"
# include "utils_bonus.h"

t_philo			*ft_init_philos_bonus(t_rules *rules);
int				ft_init_rules_sem(t_rules *rules);

#endif
