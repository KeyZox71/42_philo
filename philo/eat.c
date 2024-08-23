/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:29:51 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/23 15:35:29 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_fork *fork, int id)
{
	if (id % 2)
		pthread_mutex_lock(&fork->left);
	else if (!(id % 2))
		pthread_mutex_lock(fork->right);
}

bool	philo_eat(t_philo *philo)
{
	philo->state = FORK_TAKEN;
	if (get_death(philo, RETURN))
		return (true);
	take_fork(&philo->fork, philo->id);
	log_philo(philo);
	if (&(philo->fork.left) == philo->fork.right)
		return (print_death(philo));
	if (get_death(philo, RETURN))
		return (true);
	take_fork(&philo->fork, philo->id + 1);
	log_philo(philo);
	philo->state = EAT;
	log_philo(philo);
	pthread_mutex_lock(philo->check);
	gettimeofday(&philo->eat, NULL);
	pthread_mutex_unlock(philo->check);
	if (sleep_phil(philo) == true)
		return (true);
	pthread_mutex_unlock(&philo->fork.left);
	pthread_mutex_unlock(philo->fork.right);
	pthread_mutex_lock(philo->check);
	if (philo->data.no_meal == false && philo->meal_left > 0)
		philo->meal_left--;
	pthread_mutex_unlock(philo->check);
	return (false);
}
