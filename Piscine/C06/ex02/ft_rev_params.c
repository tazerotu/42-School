/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:07:36 by ttas              #+#    #+#             */
/*   Updated: 2024/03/26 10:24:21 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	len;
	int	i;

	if (argc > 1)
	{
		i = argc - 1;
		while (i >= 1)
		{
			len = 0;
			while (argv[i][len])
			{
				len++;
			}
			write(1, argv[i], len);
			write(1, "\n", 1);
			i--;
		}
	}
	else
		write(1, "ERROR", 5);
	return (0);
}
