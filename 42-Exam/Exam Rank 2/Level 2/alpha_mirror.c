/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:18:02 by ttas              #+#    #+#             */
/*   Updated: 2024/06/13 10:23:52 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	is_maj(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = 'Z' - (c - 'A');
		write(1, &c, 1);
	}
}

void	is_min(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = 'z' - (c - 'a');
		write(1, &c, 1);
	}
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
			is_maj(av[1][i]);
			is_min(av[1][i]);
			i++;
		}
	write(1, "\n", 1);
	}
	return (0);
}
