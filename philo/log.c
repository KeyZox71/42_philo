/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:12:20 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/12 19:38:58 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_msg.h"
#include <stdio.h>

bool	print_err(uint8_t error)
{
	if (error == 0)
		printf(ERR_MAX_PHIL);
	else if (error == 1)
		printf(ERR_MAX_DIE_TIME);
	else if (error == 2)
		printf(ERR_MAX_EAT_TIME);
	else if (error == 3)
		printf(ERR_MAX_SLEEP_TIME);
	else if (error == 4)
		printf(ERR_MAX_MEAL);
	else if (error == 5)
		printf(ERR_NB_ARG);
	return (true);
}

void	log_philo(t_philo *philo)
{
	uint32_t				timestamp;
	struct timeval			t1;
	static pthread_mutex_t	print = {0};

	gettimeofday(&t1, NULL);
	pthread_mutex_lock(&print);
	timestamp = get_time_in_ms(philo->t0, t1);
	if (philo->state == EAT)
		printf("%u %hu %s", timestamp, philo->id, EATING_MSG);
	else if (philo->state == THINK)
		printf("%u %hu %s", timestamp, philo->id, THINK_MSG);
	else if (philo->state == SLEEP)
		printf("%u %hu %s", timestamp, philo->id, SLEEP_MSG);
	else if (philo->state == DEAD)
		printf("%u %hu %s", timestamp, philo->id, DIED_MSG);
	else if (philo->state == FORK_TAKEN)
		printf("%u %hu %s", timestamp, philo->id, FORK_MSG);
	pthread_mutex_unlock(&print);
}
