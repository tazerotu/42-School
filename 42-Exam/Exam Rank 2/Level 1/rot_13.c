/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:55:51 by marvin            #+#    #+#             */
/*   Updated: 2024/06/13 09:57:56 by ttas             ###   ########.fr       */
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

char	rot13_maj(char c)
{
	int	i;

	i = 0;
	while (i < 13 || c != 'Z')
	{
		c += 1;
		i++;
	}
	if (i < 13)
	{
		c = 'A';
		i++;
	}
	while (i < 13)
	{
		c += 1;
		i++;
	}
	return (c);
}

char	rot13_min(char c)
{
	int	i;

	i = 0;
	while (i < 13 || c != 'z')
	{
		c += 1;
		i++;
	}
	if (i < 13)
	{
		c = 'a';
		i++;
	}
	while (i < 13)
	{
		c += 1;
		i++;
	}
	return (c);
}

char	rot13(char c)
{
	if (c >= 'a' && c <= 'z')
		return (rot13_min(c));
	else
		return (rot13_maj(c));
}

int	main(int ac, char **av)
{
	int i = 0;
	if (ac < 2 || ac > 2)
		write(1, "\n", 1);
	else
	{
		char *str = av[1];
		while (av[1][i])
		{
			if (is_alpha(av[1][i]) == 1)
				str[i] = rot13(av[1][i]);
			write(1, &str[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}