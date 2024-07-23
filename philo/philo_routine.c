/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:24:53 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/23 18:07:56 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	*philo_routine(void *content)
{
	t_philo	philo;
//	struct timeval t1;

	philo = *(t_philo *)content;
	printf("\t\t%hu\n", philo.nbr);
	//print_philo_data(philo.data);
//	while (1)
//	{
//		gettimeofday(&t1, NULL);
//		log_philo(t1, philo);
//		sleep_phil(philo.data.eat_time);
//	}
	return (NULL);
}
