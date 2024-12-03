/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:03:16 by ttas              #+#    #+#             */
/*   Updated: 2024/12/03 12:06:12 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/Philosopher.h"

void debug(t_info *data)
{
	printf("n_philo : %d\n", data->n_philo);
	printf("time_to_die : %d\n", data->time_to_die);
	printf("time_to_eat : %d\n", data->time_to_eat);
	printf("time_to_sleep : %d\n", data->time_to_sleep);
	printf("n_eat : %d\n", data->n_eat);
}