/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:24:53 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/08 18:37:39 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	take_fork(t_fork *fork, int id)
{
	if (id % 2 && !(&fork->left == fork->right))
		pthread_mutex_lock(&fork->left);
	else if (!(id % 2))
		pthread_mutex_lock(fork->right);
}

void	*philo_routine(void *content)
{
	t_philo	*philo;

	philo = content;
	gettimeofday(&(philo->eat), NULL);
	philo->meal_left = get_meal_nb(philo->data.meal_nbr, philo->data.no_meal);
	if (!(philo->id % 2))
		usleep(10);
	while (1)
	{
		if (philo_eat(philo) == true)
			break ;
		if (philo->meal_left == 0)
			return (NULL);
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
