/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_Philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:31:18 by ttas              #+#    #+#             */
/*   Updated: 2025/01/07 09:36:09 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/Philosopher.h"

int parsing(int argc, char **argv)
{
	int i;
	int j;
	i = 1;
	while(i <= (argc - 1))
	{
		j = 0;
		while(argv[i][j])
		{
			if(ft_isdigit(argv[i][j]) == -1)
				error(ERROR_INPUT_VALUE);
			j++;
		}		
		i++;
	}
	return(VALID_INPUT);
}

t_info	*init_data(t_info *data, int argc, char **argv)
{
	struct timeval  tv;
	gettimeofday(&tv, NULL);
	data = (t_info *)malloc(sizeof(t_info));
	data->t_start = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	data->n_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if(argc == 6)
		data->n_eat = ft_atoi(argv[5]);
	init_philosopher(data);
	return (data);
}

int init_philosopher(t_info *data)
{
	int i;

	i = 0;
	data->philo = (t_philo *)malloc(data->n_philo);
	while (i < data->n_philo)
	{
		data->philo[i].n = i;
		data->philo[i].last_eat = data->time_to_eat;
		data->philo[i].is_dead = 0;
		data->philo[i].is_eating = 0;
		data->philo[i].is_thinking = 1;
		data->philo[i].is_sleeping = 0;
		i++;
	}
	return 0;
}