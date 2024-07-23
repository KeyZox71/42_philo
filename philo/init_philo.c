/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:36:59 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/23 17:53:14 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdio.h>
void init_philo(t_pdata data)
{
	t_init	init[PHILO_MAX];
	int		r;
	size_t	i;

	i = 0;
	while (i < data.philo_nbr)
	{
		init[i].data.nbr = i;
		init[i].data.data = data;
		init[i].data.state = EAT;
		init[i].data.fork = init_fork(init, i);
		r = pthread_create(&(init[i].thread), NULL, 
					 philo_routine, &init[i].data);
		if (r != 0)
			return ;
		i++;
	}
}
