/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   State.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:25:39 by ttas              #+#    #+#             */
/*   Updated: 2025/01/07 11:14:22 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/Philosopher.h"

void state(t_philo philo, long int time)
{
	struct timeval  tv;
	gettimeofday(&tv, NULL);
	double time_in_mill = ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000) - time;
	printf("%.0f : ", time_in_mill);
	if(philo.is_eating)
		printf("Philo %d, is eating\n", philo.n);
	else if(philo.is_thinking)
		printf("Philo %d, is thinking\n", philo.n);
	else if(philo.is_sleeping)
		printf("Philo %d, is sleeping\n", philo.n);
	else if(philo.is_dead)
		printf("Philo %d, is dead\n", philo.n);
}

void eating(t_philo philo, long int time)
{
	
}

void thinking(t_philo philo, long int time)
{
	
}

void sleeping(t_philo philo, long int time)
{

}
