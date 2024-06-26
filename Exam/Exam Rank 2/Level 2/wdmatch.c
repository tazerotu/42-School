/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:46:30 by marvin            #+#    #+#             */
/*   Updated: 2024/06/19 08:46:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0, j = 0;
	if (ac != 3)
		write(1, "\n", 1);
	while (av[2][i])
	{
		if (av[2][i] == av[1][j])
			j++;
		i++;
	}
	if(av[1][j] == '\0')
	{
		i = 0;
		while (i < j)
		{
			write(1, &av[1][i], 1);
			i++;
		}		
	}
	write(1, "\n", 1);
	return 0;
}