/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:29:08 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/22 17:37:26 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	init_fork(t_init *init, uint16_t i)
{
	t_fork	fork;
	
	if (i != 0)
		fork.right = &(init[i - 1].data.fork.left);
	else
		fork.right = &(init[init[i].data.data.philo_nbr - 1].data.fork.left);
	pthread_mutex_init(&(init[i].data.fork.left), NULL);
	return (fork);
}
