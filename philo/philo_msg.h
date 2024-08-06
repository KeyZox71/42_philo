/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:50:46 by adjoly            #+#    #+#             */
/*   Updated: 2024/08/06 19:47:17 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_MSG_H
# define PHILO_MSG_H

# define EATING_MSG "is eating\n"
# define THINK_MSG "is thinking\n"
# define SLEEP_MSG "is sleeping\n"
# define DIED_MSG "died\n"
# define FORK_MSG "has taken a fork\n"

# define ERR_MAX_PHIL "Too much philo < 200\n" // err 0
# define ERR_MAX_DIE_TIME "Time to die too long < INT_MAX\n" // err 1
# define ERR_MAX_EAT_TIME "Time to eat too long < INT_MAX\n" // err 2
# define ERR_MAX_SLEEP_TIME "Time to sleep too long < INT_MAX\n" // err 3
# define ERR_MAX_MEAL "Too much meal < 1000\n" // err 4
# define ERR_NB_ARG "Invalid number of args 4 or 5\n" // err 5

#endif
