/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:18:22 by ttas              #+#    #+#             */
/*   Updated: 2024/04/24 09:15:55 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_whitespace(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	char	signe;
	int		resultat;

	resultat = 0;
	signe = 1;
	i = 0;
	while (nptr[i])
	{
		i = ft_whitespace((char *)nptr, i);
		if (nptr[i] == '-' || nptr[i] == '+')
		{
			if (nptr[i] == '-')
				signe *= -1;
			i++;
		}
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			resultat = (10 * resultat + (nptr[i] - '0'));
			i++;
		}
		return (resultat * signe);
	}
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	int	result;

// 	if (argc != 2)
// 	{
// 		printf("Erreur, vous ne pouvez pas fournir plus qu'un parametre");
// 	}
// 	else
// 	{
// 		printf("le parametre donne est : %s\n\n", argv[1]);
// 		result = ft_atoi(argv[1]);
// 		printf("le resultat apres atoi est : %d\n", result);
// 		printf("\n\nReference : %d", atoi(argv[1]));
// 	}
// 	return (0);
// }
