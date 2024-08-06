/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:24:53 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/06 18:55:55 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>


void take_fork(t_fork *fork, int id)
{
	if (id % 2 && !(&fork->left == fork->right))
		pthread_mutex_lock(&fork->left);
	else if (!(id % 2))
		pthread_mutex_lock(fork->right);
}

void	*philo_routine(void *content)
{
	t_philo	*philo;
	bool	death;

	philo = content;
	gettimeofday(&(philo->eat), NULL);
	philo->meal_left = get_meal_nb(philo->data.meal_nbr, philo->data.no_meal);
	while (1)
	{
		philo->state = FORK_TAKEN;
		take_fork(&philo->fork, philo->id);
		pthread_mutex_lock(philo->check);
		death = get_death(false, true);
		pthread_mutex_unlock(philo->check);
		if (death == true)
			break ;
		log_philo(*philo);
		if (&(philo->fork.left) == philo->fork.right)
		{
			philo->state = DEAD;
			sleep_phil(philo);
			log_philo(*philo);
			return (NULL);
		}
		take_fork(&philo->fork, philo->id + 1);
		pthread_mutex_lock(philo->check);
		death = get_death(false, true);
		pthread_mutex_unlock(philo->check);
		if (death == true)
			break ;
		log_philo(*philo);
		philo->state = EAT;
		gettimeofday(&(philo->eat), NULL);
		log_philo(*philo);
		if (sleep_phil(philo) == true)
			break ;
		pthread_mutex_unlock(&philo->fork.left);
		pthread_mutex_unlock(philo->fork.right);
		philo->meal_left--;
		philo->state = SLEEP;
		log_philo(*philo);
		sleep_phil(philo);
		philo->state = THINK;
		log_philo(*philo);
		if (philo->meal_left == 0)
			return (NULL);
	}
	pthread_mutex_unlock(&philo->fork.left);
	pthread_mutex_unlock(philo->fork.right);
	philo->state = DEAD;
	log_philo(*philo);
	return (NULL);
}
