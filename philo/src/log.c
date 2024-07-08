/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:12:20 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/07 17:56:28 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_msg.h"

void	log_philo(uint32_t timestamp, uint16_t philo, t_philo_state type)
{
	if (type == EAT)
		printf("%u %hu %s", timestamp, philo, EATING_MSG);
	else if (type == THINK)
		printf("%u %hu %s", timestamp, philo, THINK_MSG);
	else if (type == SLEEP)
		printf("%u %hu %s", timestamp, philo, SLEEP_MSG);
	else if (type == DIED)
		printf("%u %hu %s", timestamp, philo, DIED_MSG);
	else if (type == FORK_TAKEN)
		printf("%u %hu %s", timestamp, philo, FORK_MSG);
}
