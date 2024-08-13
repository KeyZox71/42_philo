/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:25:34 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/13 10:33:07 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

bool	check_args(char **av)
{
	char	**tmp;
	char	*a;

	tmp = av;
	while (*tmp)
	{
		a = *tmp;
		while (*a)
		{
			if (!ft_isdigit(*a))
				return (true);
			a++;
		}
		tmp++;
	}
	return (false);
}
