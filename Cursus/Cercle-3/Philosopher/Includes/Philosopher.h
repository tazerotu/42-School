/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:27:12 by ttas              #+#    #+#             */
/*   Updated: 2025/01/07 10:31:36 by ttas             ###   ########.fr       */
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
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>

# undef __bool_true_false_are_defined

// VALID Handling
# define VALID_INPUT 101
# define VALID_DATA_INIT 201
# define VALID_PHILO_INIT 202

// ERROR Handling
# define ERROR_INPUT -101
# define ERROR_INPUT_VALUE -102
# define ERROR_DATA_INIT -201
# define ERROR_PHILO_INIT -202

// Struct
typedef struct s_philo
{
	int				n;
	int 			last_eat;
	bool			is_eating;
	bool			is_sleeping;
	bool			is_thinking;
	bool			is_dead;
	pthread_t		thread;
	pthread_mutex_t	lfork;
	pthread_mutex_t	rfork;
}					t_philo;

typedef struct s_info
{
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_eat;
	long int		t_start;
	t_philo			*philo;
}					t_info;

// Functions
// Init
t_info		*init_data(t_info *data, int argc, char **argv);
int			init_philosopher(t_info *data);
int 		parsing(int argc, char **argv);

// State
void state(t_philo philo, long int time);

// Utils
void		error(int error_code);

// Libft
int			ft_atoi(char *nbr);
int			ft_isdigit(int c);

// Debug
void 		debug(t_info *data);

#endif