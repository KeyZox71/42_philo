/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:12:20 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/22 21:21:21 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_msg.h"
#include <stdio.h>

void	log_philo(struct timeval t1, t_philo philo)
{
	uint32_t				timestamp;
	static pthread_mutex_t	print = {0};

	timestamp = get_time_in_ms(philo.t0, t1);
	pthread_mutex_lock(&print);
	if (philo.state == EAT)
		printf("%u %hu %s", timestamp, philo.nbr, EATING_MSG);
	else if (philo.state == THINK)
		printf("%u %hu %s", timestamp, philo.nbr, THINK_MSG);
	else if (philo.state == SLEEP)
		printf("%u %hu %s", timestamp, philo.nbr, SLEEP_MSG);
	else if (philo.state == DIED)
		printf("%u %hu %s", timestamp, philo.nbr, DIED_MSG);
	else if (philo.state == FORK_TAKEN)
		printf("%u %hu %s", timestamp, philo.nbr, FORK_MSG);
	pthread_mutex_unlock(&print);
}
