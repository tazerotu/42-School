/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:28:26 by ttas              #+#    #+#             */
/*   Updated: 2024/03/22 11:53:06 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

int	ft_fibonacci(int index)
{
	int	term1;
	int	term2;
	int	nextterm;

	term1 = 0;
	term2 = 1;
	nextterm = 0;
	while (index > 0)
	{
		term1 = term2;
		term2 = nextterm;
		nextterm = term1 + term2;
		index--;
	}
	return (nextterm);
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
		result = ft_fibonacci(atoi(argv[1]));
		printf("le resultat apres la fonction est : %d\n", result);
	}
	return (0);
}
*/
