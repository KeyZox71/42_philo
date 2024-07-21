/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:31:21 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/18 19:08:43 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	start_philo(t_philo *philo, t_pdata data)
{
	int	i;
	int	ret;
	
	i = 0;
	while (philo[i] && i < data.philo_nbr)
	{
		ret = pthread_join(&(philo->thread), NULL);
		if (ret != 0)
			return ;
		i++;
	}
}
