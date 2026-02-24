/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:25:57 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 22:37:22 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putnbr_fd(long n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = '0' + (n % 10);
	write(fd, &c, 1);
}

void	ft_free(void **addr_ptr)
{
	if (addr_ptr && *addr_ptr)
	{
		free(*addr_ptr);
		*addr_ptr = NULL;
	}
}

void	ft_safe_print(t_philo *p, char *msg)
{
	long	time;

	pthread_mutex_lock(&p->rules->print);
	pthread_mutex_lock(&p->rules->death);
	if (!p->rules->is_dead)
	{
		time = ft_gettime() - p->rules->start_time;
		ft_putnbr_fd(time, 1);
		write(1, " ", 1);
		ft_putnbr_fd((long)p->id, 1);
		write(1, " ", 1);
		write(1, msg, ft_strlen(msg));
		write(1, "\n", 1);
	}
	pthread_mutex_unlock(&p->rules->death);
	pthread_mutex_unlock(&p->rules->print);
}
