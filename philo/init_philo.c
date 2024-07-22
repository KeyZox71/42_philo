/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:36:59 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/22 14:05:52 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philo(t_pdata data)
{
	t_init			init[PHILO_MAX];
	pthread_mutex_t	*print;
	int				ret;

	i = 0;
	init_fork(philo, data);
	while (i < data->philo_nbr)
	{
		ret = pthread_create(&(init[i]->thread), NULL, philo_routine, tmp);
		if (ret != 0)
			return ;
		init[i]->philo->nbr = i;
		gettimeofday(&(init[i]->philo->t0), NULL)
		init[i]->philo->data = data;
		init[i]->philo->state = EAT;
		init[i]->philo->fork = init_fork(init, i, data->philo_nbr);
		i++;
	}
}
