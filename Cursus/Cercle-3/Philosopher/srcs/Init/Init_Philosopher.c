/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_Philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:31:18 by ttas              #+#    #+#             */
/*   Updated: 2024/12/03 11:23:39 by ttas             ###   ########.fr       */
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
}

int	init_data(t_info *data, int argc, char **argv)
{
	data->n_philo = ft_atoi(argv[1]);
	return (VALID_DATA_INIT);
}

int init_philosopher(t_info *data)
{
	
}