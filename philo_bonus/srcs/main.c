/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:20:25 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 05:26:28 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/base_bonus.h"
#include "../includes/init_bonus.h"
#include "../includes/routine_bonus.h"
#include "../includes/utils_bonus.h"

static void	ft_waitpid_loop(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		waitpid(rules->pids[i], NULL, 0);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_rules	rules;

	if (!ft_init_rules(&rules, ac, av))
		ft_fatal("bad args");
	ft_init_sems(&rules);
	rules.pids = malloc(sizeof(pid_t) * rules.nb_philo);
	if (!rules.pids)
		ft_fatal("malloc failed");
	rules.start_time = ft_get_time();
	ft_fork_loop(&rules);
	ft_wait_loop(&rules);
	ft_kill_loop(&rules);
	ft_waitpid_loop(&rules);
	free(rules.pids);
	ft_cleanup_parent(&rules);
	return (0);
}
