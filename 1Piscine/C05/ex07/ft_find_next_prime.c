/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:56:14 by ttas              #+#    #+#             */
/*   Updated: 2024/03/27 14:40:13 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

int	ft_find_next_prime(int nb)
{
	int	mod;

	mod = 2;
	if (nb <= 1)
		return (0);
	while (mod < nb)
	{
		if (nb % mod == 0)
		{
			nb++;
			mod = 1;
		}
		mod++;
	}
	return (nb);
}

/*
int	main(int argc, char *argv[])
{
	int	result;

	if (argc != 2)
	{
		printf("Erreur, vous ne pouvez pas fournir plus qu'un parametre");
	}
	else
	{
		printf("le parametre donne est : %s\n\n", argv[1]);
		result = ft_find_next_prime(atoi(argv[1]));
		printf("le resultat apres la fonction est : %d\n", result);
	}
	return (0);
}
*/
