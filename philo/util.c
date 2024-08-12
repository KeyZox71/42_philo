/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:20:49 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/12 19:28:24 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(char *s)
{
	char	*tmp;

	tmp = s;
	while (*tmp)
		tmp++;
	return (tmp - s);
}

long long	ft_atoll(const char	*nptr)
{
	char		sign;
	long long	nbr;

	sign = 1;
	nbr = 0;
	while ((*nptr >= 7 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
	{
		sign *= -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nbr = nbr * 10 + (*nptr - '0');
		nptr++;
	}
	return (nbr * sign);
}

uint32_t	get_time_in_ms(struct timeval t0, struct timeval t1)
{
	return (((t1.tv_sec - t0.tv_sec) * 1000000 + \
	t1.tv_usec - t0.tv_usec) / 1000);
}

bool	print_death(t_philo *philo)
{
	get_death(philo, TRUE);
	philo->state = DEAD;
	log_philo(philo);
	return (true);
}

bool	get_death(t_philo *philo, t_bool_death set)
{
	bool	ret;

	pthread_mutex_lock(philo->check);
	if (set != RETURN)
		*(philo->death) = true;
	ret = *philo->death;
	pthread_mutex_unlock(philo->check);
	return (ret);
}
