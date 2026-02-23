/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_parent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:20:25 by demane            #+#    #+#             */
/*   Updated: 2026/02/20 22:44:15 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/base_bonus.h"

void	ft_cleanup_parent(t_rules *rules)
{
	sem_close(rules->forks);
	sem_close(rules->print);
	sem_unlink("/forks");
	sem_unlink("/print");
}
