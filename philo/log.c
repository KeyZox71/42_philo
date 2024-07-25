/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:12:20 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/24 23:56:07 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_msg.h"
#include <stdio.h>

void	log_philo(t_philo philo)
{
	uint32_t				timestamp;
	struct timeval			t1;
	static pthread_mutex_t	print = {0};

	gettimeofday(&t1, NULL);
	timestamp = get_time_in_ms(philo.t0, t1);
	pthread_mutex_lock(&print);
	if (philo.state == EAT)
		printf("%u %hu %s", timestamp, philo.id, EATING_MSG);
	else if (philo.state == THINK)
		printf("%u %hu %s", timestamp, philo.id, THINK_MSG);
	else if (philo.state == SLEEP)
		printf("%u %hu %s", timestamp, philo.id, SLEEP_MSG);
	else if (philo.state == DEAD)
		printf("%u %hu %s", timestamp, philo.id, DIED_MSG);
	else if (philo.state == FORK_TAKEN)
		printf("%u %hu %s", timestamp, philo.id, FORK_MSG);
	pthread_mutex_unlock(&print);
}
