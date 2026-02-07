/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:25:57 by demane            #+#    #+#             */
/*   Updated: 2026/02/07 17:58:14 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	ft_free(void **addr_ptr)
{
	if (addr_ptr && *addr_ptr)
	{
		free(*addr_ptr);
	}
	*addr_ptr = NULL;
}

long	ft_gettime(void)
{
	t_timeval	tv;
	long		time;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}
