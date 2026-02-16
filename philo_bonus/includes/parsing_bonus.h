/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:26:26 by demane            #+#    #+#             */
/*   Updated: 2026/02/12 16:27:11 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "base_bonus.h"
# include "utils_bonus.h"
# include <limits.h>

int		ft_atoi(char *str);
long	ft_atol(char *str);
t_rules	*ft_parse_arg(int ac, char **av);

#endif
