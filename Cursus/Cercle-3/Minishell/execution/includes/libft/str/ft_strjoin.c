/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:33:04 by ttas              #+#    #+#             */
/*   Updated: 2025/03/18 11:07:07 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
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
	free((char *)s1);
	return (ret);
}

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