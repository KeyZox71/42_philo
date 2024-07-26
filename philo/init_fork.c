/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:29:08 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/26 15:24:07 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_fork(t_pdata data)
{
	uint16_t	i;
	t_init		init[PHILO_MAX];


	i = 0;
	while (i < data.philo_nbr)
	{
		pthread_mutex_init(&(init[i].data.fork.left), NULL);
		init[i].data.fork.right = &init[(i - 1) % data.philo_nbr].data.fork.left;
		i++;
	}
	init_philo(data, init);
}
