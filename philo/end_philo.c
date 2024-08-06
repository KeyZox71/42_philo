/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:19:14 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/26 16:50:54 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_philo(pthread_t *thread, uint16_t philo_nbr)
{
	uint16_t	i;
	int			r;

	i = 0;
	while (i < philo_nbr)
	{
		r = pthread_join(thread[i], NULL);
		if (r != 0)
			return ;
		i++;
	}
}
