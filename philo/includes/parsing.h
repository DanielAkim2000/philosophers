/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:59:23 by demane            #+#    #+#             */
/*   Updated: 2026/02/08 00:42:33 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "base.h"
# include "utils.h"
# include <limits.h>

int		ft_atoi(char *str);
long	ft_atol(char *str);
t_rules	*ft_parse_arg(int ac, char **av);

#endif
