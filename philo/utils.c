/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:20:49 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/31 21:55:16 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint16_t	get_meal_nb(uint16_t meal_nbr, bool no_meal)
{
	if (no_meal == true)
		return (1);
	else
		return (meal_nbr);
}
