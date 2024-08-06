/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:29:08 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/31 17:40:57 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	init_fork(t_pdata data)
{
	uint8_t	i;
	t_philo	philo[PHILO_MAX];

	i = 0;
	while (i < data.philo_nbr)
	{
		pthread_mutex_init(&(philo[i].fork.left), NULL);
		philo[i].fork.right = &philo[(i + 1) % data.philo_nbr].fork.left;
		i++;
	}
	init_philo(data, philo);
}
