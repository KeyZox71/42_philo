/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:16:45 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/08 18:16:53 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint16_t	get_meal_nb(uint16_t meal_nbr, bool no_meal)
{
	if (no_meal == true)
		return (1);
	else
		return (meal_nbr);
}

uint32_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

bool	get_death(bool in, bool ret, t_philo *philo)
{
	static bool	death;

	pthread_mutex_lock(philo->check);
	if (ret == false)
		death = in;
	pthread_mutex_unlock(philo->check);
	return (death);
}

uint32_t	get_time_in_ms(struct timeval t0, struct timeval t1)
{
	return (((t1.tv_sec - t0.tv_sec) * 1000000 + \
	t1.tv_usec - t0.tv_usec) / 1000);
}

bool	print_death(t_philo *philo)
{
	philo->state = DEAD;
	log_philo(philo);
	return (true);
}
