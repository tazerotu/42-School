/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:03:12 by clai-ton          #+#    #+#             */
/*   Updated: 2025/04/28 16:08:49 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		++i;
	}
	return (0);
}

static int	ft_split_count(char *str, char *charset)
{
	int	str_idx;
	int	is_new_split;
	int	count;

	str_idx = 0;
	is_new_split = 0;
	count = 0;
	while (str[str_idx])
	{
		if (is_new_split == 0
			&& ft_is_in_charset(str[str_idx], charset) == 0)
		{
			is_new_split = 1;
			++count;
		}
		else if (is_new_split == 1
			&& ft_is_in_charset(str[str_idx], charset) == 1)
			is_new_split = 0;
		++str_idx;
	}
	return (count);
}

static char	*ft_strdup_split(char *src, int *src_idx, int word_size)
{
	char	*dest;
	int		i;

	dest = (char *) malloc((word_size + 1) * sizeof(char));
	if (dest == 0)
		return (dest);
	i = 0;
	while (i < word_size)
	{
		dest[i] = src[*src_idx];
		++i;
		++(*src_idx);
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_find_word_size(char *str, int idx, char *charset)
{
	int	i;

	i = 0;
	while (str[idx + i] && ft_is_in_charset(str[idx + i], charset) == 0)
		++i;
	return (i);
}

char	**ft_split_set(char *str, char *charset)
{
	char	**res;
	int		res_idx;
	int		str_idx;
	int		count;
	int		word_size;

	count = ft_split_count(str, charset);
	res = (char **) malloc(sizeof(char *) * (count + 1));
	str_idx = 0;
	res_idx = 0;
	res[count] = NULL;
	while (res_idx < count)
	{
		while (ft_is_in_charset(str[str_idx], charset) == 1
			&& str[str_idx])
			++str_idx;
		word_size = ft_find_word_size(str, str_idx, charset);
		if (word_size >= 0)
		{
			res[res_idx] = ft_strdup_split(str, &str_idx, word_size);
			++res_idx;
		}
	}
	return (res);
}
