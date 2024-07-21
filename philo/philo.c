/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:10:29 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/10 18:47:00 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <limits.h>
#include "utils.h"

int	main(int ac, char **av)
{
	t_pdata			data;
	struct timeval	t0;
	struct timeval	t1;

	gettimeofday(&t0, NULL);
	data = philo_parse(av, ac);
	gettimeofday(&t1, NULL);
	if (data.error == true)
		return (EXIT_FAILURE);
	print_philo_data(data);
	log_philo(get_time_in_ms(t0, t1), 0, DIED);
}
