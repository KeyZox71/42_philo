/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:11:02 by adjoly            #+#    #+#             */
/*   Updated: 2024/07/23 17:23:38 by adjoly           ###   ########.fr       */
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

# define PHILO_MAX 200

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

typedef struct s_fork
{
	pthread_mutex_t	left;
	pthread_mutex_t	*right;
}	t_fork;

typedef struct s_philo
{
	uint16_t		nbr;
	struct timeval	t0;
	t_fork			fork;
	t_pstate		state;
	t_pdata			data;
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
void		log_philo(struct timeval t1, t_philo philo);
void		sleep_phil(uint32_t sleep_time);

/**
 *	Main path
 *	by order of call
 */
void	init_philo(t_pdata data);
t_fork	init_fork(t_init *init, uint16_t nbr);

void	*philo_routine(void *content);

/**
 *	For debug purpose to be REMOVED
 */
void		print_philo_data(t_pdata data);

#endif
