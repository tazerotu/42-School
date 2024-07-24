/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:10:40 by ttas              #+#    #+#             */
/*   Updated: 2024/07/08 08:05:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char *str, char c)
{
	size_t	i;
	int		trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words((char *)s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	j = 0;
	i = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j] = word_dup(s, index, i);
			index = -1;
			j++;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

// if (s[j] == c)
// {
// 	if (i == 0)
// 	{
// 		split[i] = malloc(j + 1);
// 		if (!split[i])
// 		{
// 			ft_free(split, i);
// 			return (NULL);
// 		}
// 		ft_strlcpy(split[i], s, j + 1);
// 	}
// 	split[i] = malloc(j - ft_strlen(split[i - 1]) + 1);
// 	if (!split[i])
// 	{
// 		ft_free(split, i);
// 		return (NULL);
// 	}
// 	ft_strlcpy(split[i], s + ft_strlen(split[i - 1]), j
// 		- ft_strlen(split[i - 1]) + 1);
// 	i++;
// }