/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:29:08 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/25 19:49:35 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_init	*init_fork(t_init *init, uint16_t philo_nbr)
{
	uint16_t	i;

	i = 0;
	while (i < philo_nbr)
	{
		pthread_mutex_init(&(init[i].data.fork.left), NULL);
		init[i].data.fork.right = &init[(i - 1) % philo_nbr].data.fork.left;
		i++;
	}
	return (init);
}
