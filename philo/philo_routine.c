/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:24:53 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/12 21:03:47 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	*philo_routine(void *content)
{
	t_philo	*philo;

	philo = content;
	if (!(philo->id % 2))
		usleep(10);
	while (1)
	{
		if (philo_eat(philo))
			break ;
		philo->state = SLEEP;
		log_philo(philo);
		if (sleep_phil(philo))
			break ;
		philo->state = THINK;
		log_philo(philo);
	}
	pthread_mutex_unlock(&philo->fork.left);
	pthread_mutex_unlock(philo->fork.right);
	return (NULL);
}
