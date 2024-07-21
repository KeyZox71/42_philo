/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_in_ms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:02:24 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/16 21:12:05 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdint.h>

uint16_t	get_time_in_ms(struct timeval t0, struct timeval t1)
{
	int	diff;

	diff = t1.tv_sec - t0.tv_sec;
	return (((diff) * 1000000 + diff) / 1000);
}
