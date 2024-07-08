/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:11:02 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/07 16:18:23 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdint.h>

typedef enum s_philo_state 
{
	DIED = -1,
	EAT,
	THINK,
	SLEEP,
	FORK_TAKEN
}	t_philo_state;

void	log_philo(uint32_t timestamp, uint16_t philo, t_philo_state type);

#endif
