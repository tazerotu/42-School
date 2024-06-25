/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:47:03 by ttas              #+#    #+#             */
/*   Updated: 2024/03/27 14:33:15 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 1)
		return (0);
	else if (nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
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
		result = ft_recursive_factorial(atoi(argv[1]));
		printf("le resultat apres factorial est : %d\n", result);
	}
	return (0);
}
*/
