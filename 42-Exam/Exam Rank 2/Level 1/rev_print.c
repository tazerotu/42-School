/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:50:34 by marvin            #+#    #+#             */
/*   Updated: 2024/06/13 09:55:55 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int i;
	if (ac < 2 || ac > 2)
		return (0);
	else if (ac == 2)
	{
		i = ft_strlen(av[1]);
		while (i > 0)
		{
			write(1, &av[1][i], 1);
			i--;
		}
		write(1, "\n", 1);
	}
}