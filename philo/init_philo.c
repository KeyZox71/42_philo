/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:36:59 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/08 18:07:47 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	init_philo(t_pdata data, t_philo *philo)
{
	int				r;
	pthread_mutex_t	check;
	pthread_t		thread[PHILO_MAX];
	struct timeval	time;
	uint8_t			i;

	i = 0;
	pthread_mutex_init(&check, NULL);
	philo[i].check = &check;
	get_death(false, false, philo);
	gettimeofday(&time, NULL);
	while (i < data.philo_nbr)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].check = &check;
		philo[i].t0 = time;
		r = pthread_create(&thread[i], NULL, philo_routine, &philo[i]);
		if (r != 0)
			break ;
		i++;
	}
	end_philo(thread, data.philo_nbr);
}
