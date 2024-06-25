/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:39:07 by ttas              #+#    #+#             */
/*   Updated: 2024/03/27 13:56:00 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	i;

	i = 0;
	if (min >= max)
		range = NULL;
	tab = malloc(sizeof(int) * (max - min));
	if (tab == NULL)
		range = NULL;
	while (min < max)
	{
		tab[i] = min++;
		i++;
	}
	return (i - 1);
}
