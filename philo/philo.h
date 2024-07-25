/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:11:02 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/25 00:03:53 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdint.h>
# include <stdbool.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>

# define PHILO_MAX 200

typedef enum s_pstate
{
	DEAD = -1,
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

typedef struct s_fork
{
	pthread_mutex_t	left;
	pthread_mutex_t	*right;
}	t_fork;

typedef struct s_philo
{
	uint16_t		id;
	struct timeval	t0;
	t_fork			fork;
	t_pstate		state;
	t_pdata			data;
	pthread_mutex_t	*check;
}	t_philo;

typedef struct s_init
{
	pthread_t		thread;
	t_philo			data;
}	t_init;

/**
 *	Utils
 */
t_pdata		philo_parse(char **argv, int ac);
long long	ft_atoll(const char	*nptr);
uint16_t	get_time_in_ms(struct timeval t0, struct timeval t1);
void		log_philo(t_philo philo);
bool		sleep_phil(uint32_t sleep_time, pthread_mutex_t *death);
bool		get_death(bool in, bool ret);

/**
 *	Main path
 *	by order of call
 */
void	init_philo(t_pdata data);
void	init_fork(t_init *init, uint16_t philo_nbr);
void	start_philo(t_init *init, uint16_t philo_nbr);

void	*philo_routine(void *content);

/**
 *	For debug purpose to be REMOVED
 */
void		print_philo_data(t_pdata data);

#endif
