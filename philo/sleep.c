/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:15:24 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/06 18:45:19 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define SLEEP_SLICE_MS 2

uint32_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

bool	sleep_phil(t_philo *philo)
{
	struct timeval	t1;
	uint32_t		sleep_time;
	bool			death;

	sleep_time = 0;
	if (philo->state == EAT)
		sleep_time = philo->data.eat_time + get_current_time();
	else if (philo->state == SLEEP)
		sleep_time = philo->data.sleep_time + get_current_time();
	else if (philo->state == DEAD)
		sleep_time = philo->data.die_time + get_current_time();
	while (get_current_time() < sleep_time)
	{
		pthread_mutex_lock(philo->check);
		death = get_death(false, true);
		pthread_mutex_unlock(philo->check);
		if (death == true)
			return (true);
		gettimeofday(&t1, NULL);
		if (get_time_in_ms(philo->eat, t1) > philo->data.die_time)
		{
			pthread_mutex_lock(philo->check);
			get_death(true, false);
			pthread_mutex_unlock(philo->check);
			return (true);
		}
		usleep(SLEEP_SLICE_MS * 1000);
	}
	return (false);
}
