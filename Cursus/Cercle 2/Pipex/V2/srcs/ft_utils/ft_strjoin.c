/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:33:04 by ttas              #+#    #+#             */
/*   Updated: 2024/07/04 16:17:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/Pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	tab = (char *)malloc(sizeof(*tab) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (tab == 0)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tab[i] = s2[j];
		j++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
