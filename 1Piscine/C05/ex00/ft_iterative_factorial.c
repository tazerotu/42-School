/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:06:43 by ttas              #+#    #+#             */
/*   Updated: 2024/03/21 12:14:01 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	i = 1;
	result = 1;
	if (nb <= 0)
		return (0);
	else
	{
		while (i <= nb)
		{
			result = result * i;
			i++;
		}
	}
	return (result);
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
		result = ft_iterative_factorial(atoi(argv[1]));
		printf("le resultat apres factorial est : %d\n", result);
	}
	return (0);
}
*/
