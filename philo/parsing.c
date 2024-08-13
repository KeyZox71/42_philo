/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:30:46 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/13 10:32:25 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo_msg.h"

bool	print_err(uint8_t error);
bool	check_args(char **av);

bool	check_av(char **av)
{
	if (!av)
		return (print_err(5));
	if (ft_strlen(av[0]) > 3 || ft_atoll(av[0]) > 200)
		return (print_err(0));
	if (ft_strlen(av[1]) > 11)
		return (print_err(1));
	if (ft_strlen(av[2]) > 11)
		return (print_err(2));
	if (ft_strlen(av[3]) > 11)
		return (print_err(3));
	if (av[4] && ft_strlen(av[4]) > 4)
		return (print_err(4));
	return (false);
}

t_pdata	ret_err(t_pdata data, uint8_t error)
{
	print_err(error);
	data.error = true;
	return (data);
}

t_pdata	meal_nb(char **av, t_pdata data)
{
	if (av[4])
	{
		data.meal_nbr = ft_atoll(av[4]);
		if (data.meal_nbr > 1000)
			return (ret_err(data, 4));
		data.no_meal = false;
	}
	else
		data.no_meal = true;
	return (data);
}


t_pdata	fill_pdata(char **av)
{
	t_pdata	data;

	data.philo_nbr = 0;
	if (!av || check_av(av))
		return (ret_err(data, 255));
	data.philo_nbr = ft_atoll(av[0]);
	if (data.philo_nbr > 200)
		return (ret_err(data, 0));
	data.die_time = ft_atoll(av[1]);
	if (data.die_time > 2147483647)
		return (ret_err(data, 1));
	data.eat_time = ft_atoll(av[2]);
	if (data.eat_time > 2147483647)
		return (ret_err(data, 2));
	data.sleep_time = ft_atoll(av[3]);
	if (data.sleep_time > 2147483647)
		return (ret_err(data, 3));
	data = meal_nb(av, data);
	data.error = false;
	return (data);
}

t_pdata	philo_parse(char **av, int ac)
{
	t_pdata	data;

	data.philo_nbr = 0;
	if (!(ac > 4 && ac <= 6))
		return (ret_err(data, 5));
	if (check_args(av))
		return (ret_err(data, 6));
	return (fill_pdata(av));
}
