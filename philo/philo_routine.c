/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:24:53 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/31 22:10:31 by adjoly           ###   ########.fr       */
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
		if (eat(philo) == true)
			break ;
		// unlock pas les fourchet si po la
		pthread_mutex_unlock(&philo->fork.left);
		pthread_mutex_unlock(philo->fork.right);
		if (philo->data.no_meal == false)
			philo->meal_left--;
		philo->state = SLEEP;
		log_philo(*philo);
		death = sleep_phil(*philo);
		if (death == true)
			break ;
		if (!philo->meal_left)
			return (NULL);
		philo->state = THINK;
		log_philo(*philo);
	}
	philo->state = DEAD;
	log_philo(*philo);
	return (NULL);
}
