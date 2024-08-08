/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:29:51 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/08 18:05:07 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_eat(t_philo *philo)
{
	philo->state = FORK_TAKEN;
	take_fork(&philo->fork, philo->id);
	if (get_death(false, true, philo))
		return (true);
	log_philo(philo);
	if (&(philo->fork.left) == philo->fork.right)
		return (true);
	take_fork(&philo->fork, philo->id + 1);
	if (get_death(false, true, philo))
		return (true);
	log_philo(philo);
	philo->state = EAT;
	gettimeofday(&(philo->eat), NULL);
	log_philo(philo);
	if (sleep_phil(philo) == true)
		return (true);
	pthread_mutex_unlock(&philo->fork.left);
	pthread_mutex_unlock(philo->fork.right);
	philo->meal_left--;
	return (false);
}
