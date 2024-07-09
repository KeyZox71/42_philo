/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:11:02 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/09 12:04:14 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdint.h>
# include <stdbool.h>
# include <sys/time.h>

typedef enum s_pstate
{
	DIED = -1,
	EAT,
	THINK,
	SLEEP,
	FORK_TAKEN
}	t_pstate;

typedef struct s_pdata
{
	uint32_t	die_time;
	uint32_t	sleep_time;
	uint32_t	eat_time;
	uint16_t	philo_nbr;
	uint8_t		meal_nbr;
	bool		error;
}	t_pdata;

void		log_philo(uint32_t timestamp, uint16_t philo, t_pstate type);
t_pdata		philo_parse(char **argv, int ac);
uint16_t	get_time_in_ms(struct timeval t0, struct timeval t1);

/**
 *	For debug purpose to be REMOVED
 */
void		print_philo_data(t_pdata data);

#endif
