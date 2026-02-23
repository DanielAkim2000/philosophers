/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demane <emanedanielakim@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:20:25 by demane            #+#    #+#             */
/*   Updated: 2026/02/23 05:26:27 by demane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/routine_bonus.h"
#include "../../includes/utils_bonus.h"

static int	ft_take_fork(t_philo *p) {
  sem_wait(p->rules->forks);
  sem_wait(p->meal_sem);
  if (p->is_dead) {
    sem_post(p->meal_sem);
    sem_post(p->rules->forks);
    return (1);
  }
  sem_post(p->meal_sem);
  ft_print_action(p, "has taken a fork");
  return (0);
}

void	ft_eat_routine(t_philo *p) {
  if (ft_take_fork(p))
    return ;
  sem_wait(p->rules->forks);
  sem_wait(p->meal_sem);
  if (p->is_dead) {
    sem_post(p->meal_sem);
    sem_post(p->rules->forks);
    sem_post(p->rules->forks);
    return ;
  }
  sem_post(p->meal_sem);
  ft_print_action(p, "has taken a fork");
  ft_print_action(p, "is eating");
  sem_wait(p->meal_sem);
  p->last_meal = ft_get_time();
  p->meals_eaten++;
  sem_post(p->meal_sem);
  ft_sleep(p->rules->t_eat);
  sem_post(p->rules->forks);
  sem_post(p->rules->forks);
}
