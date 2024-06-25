/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:14:19 by ttas              #+#    #+#             */
/*   Updated: 2024/03/21 13:17:09 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;

	i = nb;
	if (nb < 0 || power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		nb = nb * i;
		power--;
	}
	return (nb);
}
/*
int	pow;
	int	i;

	i = 0;
	pow = 1;
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	while (i < nb)
	{
		pow = pow * power;
		i++;
	}
	return (pow);
*/
/*
int	main(int argc, char *argv[])
{
	int	result;

	if (argc != 3)
	{
		printf("Erreur, vous ne pouvez fournir que 2 parametres");
	}
	else
	{
		printf("le parametre donne est : %s\n\n", argv[1]);
		result = ft_iterative_power(atoi(argv[1]), atoi(argv[2]));
		printf("le resultat apres la fonction est : %d\n", result);
	}
	return (0);
}
*/
