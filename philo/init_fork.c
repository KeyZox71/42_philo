/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:53:01 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/18 21:03:00 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_fork(t_philo *philo, t_pdata data)
{
	int	i;

	i = 0;
	while (philo[i] && i <= data.philo_nbr)
	{
		pthread_mutex_init(philo[i].fork.left);
		if (i == data.philo_nbr)
			philo[i].fork.right = &philo[0].fork.left;
		else
			philo[i].fork.right = &philo[i + 1].fork.left;
		i++;
	}
}
