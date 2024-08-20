/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:13:35 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/20 15:43:56 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	unlock_death(t_philo *philo, uint8_t i)
{
	pthread_mutex_unlock(philo->check);
	pthread_mutex_unlock(&philo[i].fork.left);
	pthread_mutex_unlock(philo[i].fork.right);
	return (print_death(&philo[i]));
}

bool	philo_check(t_philo *philo, t_pdata data)
{
	uint8_t			i;
	struct timeval	t1;
	uint8_t			eaten;

	i = 0;
	eaten = 0;
	while (i < data.philo_nbr)
	{
		gettimeofday(&t1, NULL);
		pthread_mutex_lock(philo->check);
		if (get_time_in_ms(philo[i].eat, t1) > data.die_time + 1)
			return (unlock_death(philo, i));
		if (philo[i].meal_left == 0)
			eaten++;
		pthread_mutex_unlock(philo->check);
		if (get_death(philo, RETURN))
			return (true);
		i++;
	}
	if (eaten == data.philo_nbr)
		return (true);
	return (false);
}

void	monitor(t_philo *philo, t_pdata data)
{
	while (!philo_check(philo, data))
		usleep(100);
	get_death(philo, true);
}
