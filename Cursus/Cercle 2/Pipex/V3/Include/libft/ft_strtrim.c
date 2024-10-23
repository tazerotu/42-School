/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim (old).c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:10:04 by ttas              #+#    #+#             */
/*   Updated: 2024/05/07 10:29:48 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_str_write(char *res_str, char *str, int start, int finish)
{
	int	i;

	i = 0;
	while (start < finish)
	{
		res_str[i] = str[start];
		i++;
		start++;
	}
	res_str[i] = '\0';
	return (res_str);
}

static int	find_char(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*isempty(char const *s1, char const *set)
{
	char	*new_str;

	if (set == 0 && s1 == 0)
		return (0);
	else if (s1 == 0)
		return (0);
	else
	{
		new_str = malloc(ft_strlen(s1) + 1);
		ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
		return (new_str);
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res_str;
	int		start;
	int		finish;

	if (s1 == 0 || set == 0)
		return (isempty(s1, set));
	start = 0;
	finish = ft_strlen(s1);
	while (s1[start] && find_char(s1[start], set) == 1)
		start++;
	while (finish > start && find_char(s1[finish - 1], set) == 1)
		finish--;
	res_str = malloc(sizeof(char) * (finish - start + 1));
	if (!res_str)
		return (NULL);
	ft_str_write(res_str, (char *)s1, start, finish);
	return (res_str);
}
