/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:19:14 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/25 16:46:57 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philo(t_init *init, uint16_t philo_nbr)
{
	uint16_t	i;
	int			r;

	i = 0;
	while (i < philo_nbr)
	{
		r = pthread_join(init[i].thread, NULL);
		if (r != 0)
			return ;
		i++;
	}
}
