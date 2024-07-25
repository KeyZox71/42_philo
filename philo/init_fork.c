/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:29:08 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/24 18:47:29 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_fork(t_init *init, uint16_t philo_nbr)
{
	uint16_t	i;

	i = 0;
	while (i < philo_nbr)
	{
		pthread_mutex_init(&(init[i].data.fork.left), NULL);
		i++;
	}
	init[0].data.fork.right = &(init[philo_nbr - 1].data.fork.left);
	i = 1;
	while (i < philo_nbr)
	{
		init[i].data.fork.right = &(init[i - 1].data.fork.left);
		i++;
	}
}
