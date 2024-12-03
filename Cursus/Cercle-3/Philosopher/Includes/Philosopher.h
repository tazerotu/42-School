/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:27:12 by ttas              #+#    #+#             */
/*   Updated: 2024/12/03 10:35:22 by ttas             ###   ########.fr       */
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
# include <stdbool.h>
# include <pthread.h>

# undef __bool_true_false_are_defined

// VALID Handling
# define VALID_PHILO_INIT 201


// ERROR Handling
# define ERROR_INPUT -101
# define ERROR_PHILO_INIT -201

// Struct
typedef struct s_philo
{
	int			n;
	int 		last_eat;
	bool		is_eating;
}				t_philo;

typedef struct s_info
{
	int 		n_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			n_eat;
	long int		t_start;
	bool 		stop;
	t_philo		*philo;
}				t_info;

// Functions
// Init
int		init_philosopher(t_philo *philo, int argc, char **argv);

// Utils
void	error(int error_code);

#endif