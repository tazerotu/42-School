/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:48:38 by ttas              #+#    #+#             */
/*   Updated: 2024/06/06 09:56:57 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_whitespace(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

int	ft_atoi(char *nptr)
{
	int	i;
	int	signe;
	int	resultat;

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
