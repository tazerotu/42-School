/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:59:40 by ttas              #+#    #+#             */
/*   Updated: 2024/03/26 09:09:31 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	len;

	if (argc == 1)
	{
		len = 0;
		while (argv[0][len])
		{
			len++;
		}
		write(1, argv[0], len);
		write(1, "\n", 1);
	}
	else
		write(1, "ERROR", 5);
	return (0);
}
