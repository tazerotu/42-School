/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:39:05 by ttas              #+#    #+#             */
/*   Updated: 2024/08/01 09:04:28 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*str;

// 	if (nmemb == 0 || size == 0)
// 	{
// 		str = malloc(0);
// 		return (str);
// 	}
// 	if (nmemb >= INT_MAX || size >= INT_MAX || nmemb * size == INT_MAX)
// 		return (NULL);
// 	str = malloc(size * nmemb);
// 	if (str == NULL)
// 		return (NULL);
// 	ft_bzero(str, nmemb * size);
// 	return (str);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	char	*str;

// 	str = (char *)s;
// 	while (c > 256)
// 		c -= 256;
// 	while (*str != c)
// 	{
// 		if (*str == '\0')
// 		{
// 			return (NULL);
// 		}
// 		str++;
// 	}
// 	return (str);
// }

// void	ft_bzero(void *s, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*erase;

// 	erase = (unsigned char *)s;
// 	i = 0;
// 	while (i < n)
// 	{
// 		erase[i] = '\0';
// 		i++;
// 	}
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*ret;

// 	i = 0;
// 	j = 0;
// 	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	if (ret == NULL)
// 	{
// 		return (NULL);
// 	}
// 	while (s1[i])
// 	{
// 		ret[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 	{
// 		ret[i + j] = s2[j];
// 		j++;
// 	}
// 	ret[i + j] = '\0';
// 	free(s1);
// 	return (ret);
// }
