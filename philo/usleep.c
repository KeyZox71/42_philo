/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:15:24 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/12 20:47:05 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint32_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

uint32_t	get_sleep_time(t_philo *philo)
{
	if (philo->state == EAT)
		return (philo->data.eat_time + get_current_time());
	else if (philo->state == SLEEP)
		return (philo->data.sleep_time + get_current_time());
	else if (philo->state == DEAD)
		return (philo->data.die_time + get_current_time());
	return (0);
}

bool	sleep_phil(t_philo *philo)
{
	uint32_t	sleep_time;

	sleep_time = get_sleep_time(philo);
	while (get_current_time() < sleep_time)
	{
		if (get_death(philo, RETURN))
			return (true);
		usleep(1000);
	}
	return (false);
}
