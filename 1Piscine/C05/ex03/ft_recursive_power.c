/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:06:32 by ttas              #+#    #+#             */
/*   Updated: 2024/03/22 11:28:33 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_recursive_power(int nb, int power)
{
	if (nb < 0 || power < 0)
		return (0);
	if (power != 0)
		return (nb * ft_recursive_power(nb, power - 1));
	else
		return (1);
}

/*
int	main(int argc, char *argv[])
{
	int	result;

	if (argc != 3)
	{
		printf("Erreur, vous ne pouvez/devez fournir que 2 parametres");
	}
	else
	{
		printf("le parametre donne est : %s a la puissance de : %s\n\n",
			argv[1], argv[2]);
		result = ft_recursive_power(atoi(argv[1]), atoi(argv[2]));
		printf("le resultat apres la fonction est : %d\n", result);
	}
	return (0);
}
*/
