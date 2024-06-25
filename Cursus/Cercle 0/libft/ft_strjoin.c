/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:33:04 by ttas              #+#    #+#             */
/*   Updated: 2024/05/06 09:38:02 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*isempty(char const *s1, char const *s2)
{
	char	*new_str;

	if (s1 == 0 && s2 == 0)
	{
		new_str = malloc(0);
		return (new_str);
	}
	else if (s1 == 0)
	{
		new_str = (malloc(ft_strlen(s2) + 1));
		if (!new_str)
			return (0);
		ft_strlcpy(new_str, s2, ft_strlen(s2) + 1);
	}
	else
	{
		new_str = (malloc(ft_strlen(s1) + 1));
		if (!new_str)
			return (0);
		ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	}
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	k;

	if (s1 == 0 || s2 == 0)
		return (isempty(s1, s2));
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	else
	{
		k = ft_strlen(s1);
		ft_memcpy(res, s1, k);
		ft_strlcpy(res + k, s2, ft_strlen(s2) + 1);
		return (res);
	}
}

// while (i < ft_strlen(s1))
// 		{
// 			res[i] = s1[i];
// 			i++;
// 		}