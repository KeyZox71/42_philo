/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:24:53 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/26 15:15:13 by adjoly           ###   ########.fr       */
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
		philo.state = FORK_TAKEN;
		take_fork(&philo.fork, philo.id);
		log_philo(philo);
		take_fork(&philo.fork, philo.id + 1);
		log_philo(philo);
		philo.state = EAT;
		log_philo(philo);
		death = sleep_phil(philo.data.eat_time, philo.check);
		if (death == true)
			return (NULL);
		pthread_mutex_unlock(philo.fork.right);
		pthread_mutex_unlock(&philo.fork.left);
		i++;
	}
	return (NULL);
}
