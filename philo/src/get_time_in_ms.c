/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_in_ms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:02:24 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/09 13:14:50 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdint.h>

uint16_t	get_time_in_ms(struct timeval t0, struct timeval t1)
{
	return (((t1.tv_sec-t0.tv_sec) * 1000000 + t1.tv_usec-t0.tv_usec)/1000);
}
