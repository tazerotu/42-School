/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:27:12 by ttas              #+#    #+#             */
/*   Updated: 2024/11/20 10:45:45 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

// Includes
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>

// Error Handling
# define ERROR_INPUT -101
# define ERROR_PHILO_INIT -201

// Struct
typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef struct s_philo
{
	int		amount;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	t_bool	is_eating;
}	t_philo;

// Functions
// Init
int		init_philosopher(t_philo *philo, int argc, char **argv);

// Utils
void	error(int error_code);

#endif