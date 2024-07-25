/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:24:53 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/25 16:12:00 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	*philo_routine(void *content)
{
	t_philo	philo;
	bool	death;
	int		i = 0;

	philo = *(t_philo *)content;
	gettimeofday(&(philo.t0), NULL);
	while (i < philo.data.meal_nbr)
	{
		philo.state = EAT;
		pthread_mutex_lock(&philo.fork.left);
		pthread_mutex_lock(philo.fork.right);
		log_philo(philo);
		death = sleep_phil(philo.data.eat_time, philo.check);
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
