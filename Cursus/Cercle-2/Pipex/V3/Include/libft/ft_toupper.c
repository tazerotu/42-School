/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:45:33 by ttas              #+#    #+#             */
/*   Updated: 2024/04/24 09:28:21 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
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
// 		result = ft_toupper(argv[1][0]);
// 		printf("le resultat apres atoi est : %d\n", result);
// 		printf("\n\nReference : %d", toupper(argv[1][0]));
// 	}
// 	return (0);
// }
