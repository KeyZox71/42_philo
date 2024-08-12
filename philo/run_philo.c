/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:36:59 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/12 20:23:30 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	end_philo(pthread_t *thread, uint16_t philo_nbr)
{
	uint8_t	i;
	int		r;

	i = 0;
	while (i < philo_nbr)
	{
		r = pthread_join(thread[i], NULL);
		if (r != 0)
			return ;
		i++;
	}
}

void	init_fork(t_pdata data)
{
	uint8_t	i;
	t_philo	philo[PHILO_MAX];

	i = 0;
	while (i < data.philo_nbr)
	{
		pthread_mutex_init(&(philo[i].fork.left), NULL);
		philo[i].fork.right = &(philo[(i + 1) % data.philo_nbr].fork.left);
		i++;
	}
	init_philo(data, philo);
}

uint16_t	get_meal_nb(uint16_t meal_nbr, bool no_meal)
{
	if (no_meal == true)
		return (1);
	else
		return (meal_nbr);
}

void	init_philo(t_pdata data, t_philo *philo)
{
	pthread_mutex_t	check;
	pthread_t		thread[PHILO_MAX];
	uint8_t			i;
	bool			death;
	struct timeval	time;

	i = 0;
	death = false;
	pthread_mutex_init(&check, NULL);
	gettimeofday(&time, NULL);
	while (i < data.philo_nbr)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].check = &check;
		philo[i].eat = time;
		philo[i].t0 = time;
		philo[i].death = &death;
		philo[i].meal_left = get_meal_nb(data.meal_nbr, data.no_meal);
		pthread_create(&thread[i], NULL, philo_routine, &philo[i]);
		i++;
	}
	monitor(philo, data);
	end_philo(thread, data.philo_nbr);
}
