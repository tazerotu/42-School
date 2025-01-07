/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:27:15 by ttas              #+#    #+#             */
/*   Updated: 2025/01/07 12:36:28 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Philosopher.h"

// void freeall(t_info data)
// {
	
// }

// if(number_eat)
// while i < number_eat
// else
// while(1)

// eat, think, sleep
// if not eaten for time >= time_to_eat then die	

int routine(t_data *data)
{
	
	while(1)
	{
		if(dead_philo(data))
			return (-1);
	}
}

int	main(int argc, char **argv)
{
	t_info	*data;

	if (argc < 5 || argc > 6)
		error(ERROR_INPUT);
	data = NULL;
	parsing(argc, argv);
	data = init_data(data, argc, argv);
	if(routine(data) == -1)
		return(-1);
	// state(data->philo[0], data->t_start);
	// debug(data);
	return (0);
}
