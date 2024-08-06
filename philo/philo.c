/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:10:29 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/31 15:59:39 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <limits.h>

int	main(int ac, char **av)
{
	t_pdata			data;

	data = philo_parse(av, ac);
	if (data.error == true)
		return (EXIT_FAILURE);
	init_fork(data);
	return (EXIT_SUCCESS);
}
