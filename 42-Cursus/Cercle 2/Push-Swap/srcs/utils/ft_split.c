/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:10:40 by ttas              #+#    #+#             */
/*   Updated: 2024/06/24 09:22:30 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Count the number of words in the string
size_t	count_words(char *str, char c)
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
		{
			trigger = 0;
		}
		str++;
	}
	return (i);
}

// Duplicate a substring from str[start] to str[finish]
static char	*word_dup(char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
	{
		word[i++] = str[start++];
	}
	word[i] = '\0';
	return (word);
}

// Free the memory allocated for the split words
static void	free_split(char **split, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// Split the string s by the delimiter c
char	**ft_split(char *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	j = 0;
	i = 0;
	index = -1;
	while (i <= strlen(s))
	{
		if (s[i] != c && index < 0)
		{
			index = i;
		}
		else if ((s[i] == c || i == strlen(s)) && index >= 0)
		{
			split[j] = word_dup(s, index, i);
			if (!split[j]) // Check if malloc in word_dup failed
			{
				free_split(split, j);
				return (NULL);
			}
			index = -1;
			j++;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

// Helper function to free the split array after use
void	free_split_array(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// size_t	count_words(char *str, char c)
// {
// 	size_t	i;
// 	int		trigger;

// 	i = 0;
// 	trigger = 0;
// 	while (*str)
// 	{
// 		if (*str != c && trigger == 0)
// 		{
// 			trigger = 1;
// 			i++;
// 		}
// 		else if (*str == c)
// 			trigger = 0;
// 		str++;
// 	}
// 	return (i);
// }

// static char	*word_dup(char *str, int start, int finish)
// {
// 	char	*word;
// 	int		i;

// 	i = 0;
// 	word = malloc((finish - start + 1) * sizeof(char));
// 	while (start < finish)
// 		word[i++] = str[start++];
// 	word[i] = '\0';
// 	return (word);
// }

// char	**ft_split(char *s, char c)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		index;
// 	char	**split;

// 	split = malloc((count_words((char *)s, c) + 1) * sizeof(char *));
// 	if (!s || !split)
// 		return (0);
// 	j = 0;
// 	i = 0;
// 	index = -1;
// 	while (i <= ft_strlen(s))
// 	{
// 		if (s[i] != c && index < 0)
// 			index = i;
// 		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
// 		{
// 			split[j] = word_dup(s, index, i);
// 			index = -1;
// 			j++;
// 		}
// 		i++;
// 	}
// 	split[j] = 0;
// 	return (split);
// }

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