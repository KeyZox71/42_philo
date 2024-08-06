/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:30:46 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/31 17:52:08 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_pdata	fill_pdata(char **av)
{
	t_pdata	data;

	if (!av)
	{
		data.error = true;
		return (data);
	}
	data.philo_nbr = ft_atoll(av[1]);
	data.die_time = ft_atoll(av[2]);
	data.eat_time = ft_atoll(av[3]);
	data.sleep_time = ft_atoll(av[4]);
	if (av[5])
		data.meal_nbr = ft_atoll(av[5]);
	data.error = false;
	return (data);
}

t_pdata	philo_parse(char **av, int ac)
{
	if (!(ac > 4 && ac <= 6))
		return (fill_pdata(NULL));
	return (fill_pdata(av));
}
