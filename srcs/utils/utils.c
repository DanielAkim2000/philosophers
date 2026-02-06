/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:25:57 by demane            #+#    #+#             */
/*   Updated: 2026/02/06 15:33:15 by demane           ###   ########.fr       */
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
