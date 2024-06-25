/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:52:37 by ttas              #+#    #+#             */
/*   Updated: 2024/03/28 10:33:17 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb == 0 || nb == 1)
		return (nb);
	while (i <= nb / 2)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
/*
int	main(int argc, char *argv[])
{
	int	result;

	if (argc != 2)
	{
		printf("Erreur, vous ne pouvez/devez fournir que 1 parametres");
	}
	else
	{
		printf("le parametre donne est : %s\n\n", argv[1]);
		result = ft_sqrt(atoi(argv[1]));
		printf("le resultat apres la fonction est : %d\n", result);
	}
	return (0);
}
*/
