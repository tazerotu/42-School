/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:27:15 by ttas              #+#    #+#             */
/*   Updated: 2025/01/07 09:43:06 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Philosopher.h"

// void freeall(t_info data)
// {
	
// }

int	main(int argc, char **argv)
{
	t_info	*data;

	if (argc < 5 || argc > 6)
		error(ERROR_INPUT);
	data = NULL;
	parsing(argc, argv);
	data = init_data(data, argc, argv);
	// state(data->philo[0], data->t_start);
	// debug(data);
	return (0);
}
