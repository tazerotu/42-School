/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:33:04 by ttas              #+#    #+#             */
/*   Updated: 2024/10/02 10:34:55 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*ret;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ret == NULL)
	{
		return (NULL);
	}
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	free(s1);
	return (ret);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*tab;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	tab = (char *)malloc(sizeof(*tab) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
// 	if (tab == 0)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		tab[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 	{
// 		tab[i] = s2[j];
// 		j++;
// 		i++;
// 	}
// 	tab[i] = '\0';
// 	return (tab);
// }