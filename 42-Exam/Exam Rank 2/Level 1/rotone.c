/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:14:12 by marvin            #+#    #+#             */
/*   Updated: 2024/06/13 09:58:46 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_alpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (-1);
}

char	rotone(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		if (c == 'z')
			c = 'a';
		else
			c = c + 1;
	}
	if (c >= 'A' && c <= 'Z')
	{
		if (c == 'Z')
			c = 'A';
		else
			c = c + 1;
	}
	return (c);
}

int	main(int ac, char **av)
{
	if (ac < 2 || ac > 2)
		write(1, "\n", 1);
	else
	{
		int i = 0;
		char *str = av[1];
		while (av[1][i])
		{
			if (is_alpha(av[1][i]) == 1)
				str[i] = rotone(av[1][i]);
			write(1, &str[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}