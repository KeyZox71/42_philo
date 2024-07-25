/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:36:59 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/25 19:30:28 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void init_philo(t_pdata data)
{
	t_init	*init = malloc((sizeof(t_init) + 1) * data.philo_nbr);
	int				r;
	pthread_mutex_t	check;
	uint16_t		i;

	i = 0;
	pthread_mutex_init(&check, NULL);
	get_death(false, false);
	init_fork(init, data.philo_nbr);
	while (i < data.philo_nbr)
	{
		init[i].data.id = i + 1;
		init[i].data.state = SLEEP;
		init[i].data.data = data;
		init[i].data.check = &check;
		r = pthread_create(&init[i].thread, NULL, 
					 philo_routine, &(init[i].data));
		if (r != 0)
			break ;
		i++;
	}
	start_philo(init, i);
}
