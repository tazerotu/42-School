/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:02:46 by marvin            #+#    #+#             */
/*   Updated: 2024/06/17 15:02:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0, j = 0;
	if (ac != 3)
		return (-1);
	else
	{
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (av[1][i] == av[2][j])
				{
					int k = 0;
					while (k < i)
					{
						if (av[1][k] == av[1][i])
							break;
						k++;
					}
					if (k == i)
						write(1, &av[1][i], 1);
				}
				j++;
			}
			i++;
		}
		write(1, "\n", 1);
	}
	return 0;
}

