/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:15:24 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/30 02:48:34 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#define SLEEP_SLICE_MS 10

bool	sleep_phil(t_philo philo)
{
	struct timeval	t1;
	uint32_t		sleep_time;

	sleep_time = 0;
	if (philo.state == EAT)
		sleep_time = philo.data.eat_time;
	else if (philo.state == SLEEP)
		sleep_time = philo.data.sleep_time;
	while (sleep_time)
	{
		pthread_mutex_lock(philo.check);
		if (get_death(false, true) == true)
		{
			pthread_mutex_unlock(philo.check);
			return (true);
		}
		pthread_mutex_unlock(philo.check);
		gettimeofday(&t1, NULL);
		if (get_time_in_ms(philo.eat, t1) > philo.data.die_time)
		{
			pthread_mutex_lock(philo.check);
			get_death(true, false);
			pthread_mutex_unlock(philo.check);
			pthread_mutex_unlock(&philo.fork.left);
			pthread_mutex_unlock(philo.fork.right);
			philo.state = DEAD;
			log_philo(philo);
			return (true);
		}
		usleep(SLEEP_SLICE_MS * 1000);
		sleep_time -= SLEEP_SLICE_MS;
	}
	return (false);
}
