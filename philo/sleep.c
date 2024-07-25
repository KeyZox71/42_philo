/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:15:24 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/25 19:57:03 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint32_t	time_to_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}


#define SLEEP_SLICE_MS 10

bool	sleep_phil(uint32_t sleep_time, pthread_mutex_t *death)
{
	while (sleep_time)
	{
		pthread_mutex_lock(death);
		if (get_death(false, true) == true)
			return (true);
		pthread_mutex_unlock(death);
		usleep(SLEEP_SLICE_MS * 1000);
		sleep_time -= SLEEP_SLICE_MS;
	}
	return (false);
}
