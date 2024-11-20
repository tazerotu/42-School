/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:27:15 by ttas              #+#    #+#             */
/*   Updated: 2024/11/20 09:47:14 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Philosopher.h"

int	main(int argc, char **argv)
{
	t_philo *philo;
	
	if (argc != 4)
		error(ERROR_INPUT);
	philo = NULL;
	init_philosopher(philo, argc, argv);
	return(0);
}
