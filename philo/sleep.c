/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:15:24 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/25 16:08:44 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint32_t	time_to_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

bool	sleep_phil(uint32_t sleep_time, pthread_mutex_t *death)
{
	uint32_t	t0;

	t0 = time_to_ms() + sleep_time;
	while (time_to_ms() < t0)
	{
		pthread_mutex_lock(death);
		if (get_death(false, true) == true)
			return (true);
		pthread_mutex_unlock(death);
		usleep(1000);
	}
	return (false);
}
