/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:29:39 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/31 21:53:13 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	eat(t_philo *philo)
{
	bool	death;

	philo->state = FORK_TAKEN;
	take_fork(&philo->fork, philo->id);
	log_philo(*philo);
	if (&(philo->fork.left) == philo->fork.right)
		return (true);
	take_fork(&philo->fork, philo->id + 1);
	log_philo(*philo);
	philo->state = EAT;
	gettimeofday(&(philo->eat), NULL);
	log_philo(*philo);
	death = sleep_phil(*philo);
	return (death);
}
