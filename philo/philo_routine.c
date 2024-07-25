/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:24:53 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/25 20:06:20 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>


void take_fork(t_fork *fork, int id)
{
	if (id % 2)
	{
		pthread_mutex_lock(&fork->left);
	}
	else
	{
		pthread_mutex_lock(fork->right);
	}
}

void	*philo_routine(void *content)
{
	t_philo	philo;
	bool	death;
	int		i = 0;

	philo = *(t_philo *)content;
	gettimeofday(&(philo.t0), NULL);
	while (i < philo.data.meal_nbr)
	{
		log_philo(philo);
		take_fork(&philo.fork, philo.id);
		philo.state = FORK_TAKEN;
		log_philo(philo);
		take_fork(&philo.fork, philo.id + 1);
		log_philo(philo);
		philo.state = EAT;
		log_philo(philo);
		death = sleep_phil(philo.data.eat_time, philo.check);
		pthread_mutex_unlock(&philo.fork.left);
		pthread_mutex_unlock(philo.fork.right);
		if (death == true)
			return (NULL);
		philo.state = SLEEP;
		log_philo(philo);
		death = sleep_phil(philo.data.sleep_time, philo.check);
		if (death == true)
			return (NULL);
		philo.state = THINK;
		log_philo(philo);
		i++;
	}
	return (NULL);
}
