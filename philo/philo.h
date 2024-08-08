/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:11:02 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/08 18:12:39 by adjoly           ###   ########.fr       */
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
	uint8_t		philo_nbr;
	uint16_t	meal_nbr;
	bool		no_meal;
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
	struct timeval	eat;
	uint16_t		meal_left;
	t_fork			fork;
	t_pstate		state;
	t_pdata			data;
	pthread_mutex_t	*check;
}	t_philo;

/**
 *	Utils
 */
size_t		ft_strlen(char *s);
uint16_t	get_meal_nb(uint16_t meal_nbr, bool no_meal);
bool		get_death(bool in, bool ret, t_philo *philo);
long long	ft_atoll(const char	*nptr);
uint32_t	get_time_in_ms(struct timeval t0, struct timeval t1);
uint32_t	get_current_time(void);

void		log_philo(t_philo *philo);
bool		sleep_phil(t_philo *philo);
t_pdata		philo_parse(char **argv, int ac);
bool		print_death(t_philo *philo);
bool		philo_eat(t_philo *philo);
/**
 *	Main path
 *	by order of call
 */
void		init_fork(t_pdata data);
void		init_philo(t_pdata data, t_philo *philo);
void		end_philo(pthread_t *thread, uint16_t philo_nbr);

void		*philo_routine(void *content);

/**
 *	Routine func
 */
void		take_fork(t_fork *fork, int id);
bool		eat(t_philo *philo);

/**
 *	For debug purpose to be REMOVED
 */
void		print_philo_data(t_pdata data);

#endif
