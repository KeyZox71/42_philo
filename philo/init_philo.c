/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:36:59 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/17 22:53:48 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philo(t_pdata data)
{
	t_philo			philo[PHILO_MAX];
	t_philo			*tmp;
	pthread_mutex_t	*print;
	int				ret;

	tmp = philo;
	i = 0;
	init_fork(philo, data);
	while (tmp && i < data->philo_nbr)
	{
		ret = pthread_create(&(tmp->thread), NULL, philo_routine, tmp);
		if (ret != 0)
			return ;
		tmp->data = data;
		tmp->state = EAT;
		tmp++;
	}
}
