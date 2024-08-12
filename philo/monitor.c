/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:13:35 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/12 20:50:17 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		if (get_time_in_ms(philo[i].eat, t1) > data.die_time)
		{
			pthread_mutex_unlock(&philo[i].fork.left);
			pthread_mutex_unlock(philo[i].fork.right);
			return (print_death(&philo[i]));
		}
		if (philo[i].meal_left == 0)
			eaten++;
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
