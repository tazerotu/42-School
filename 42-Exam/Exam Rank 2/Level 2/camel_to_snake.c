/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:24:58 by ttas              #+#    #+#             */
/*   Updated: 2024/06/13 10:29:57 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	to_snake(char c)
{
	c = c + 32;
	write(1, "_", 1);
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac < 2 || ac > 2)
		write(1, "\n", 1);
	else
	{
		int i = 0;
		while (av[1][i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				to_snake(av[1][i]);
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	return (0);
}