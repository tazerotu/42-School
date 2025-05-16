/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:17:41 by ttas              #+#    #+#             */
/*   Updated: 2024/10/24 08:52:37 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
	{
		return ((char *)big);
	}
	while (*big && len >= little_len)
	{
		if (ft_strncmp(big, little, little_len) == 0)
		{
			return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*haystack = "hello, world!";
// 	const char	*needle = "world";
// 	size_t		len;
// 	char		*result;

// 	len = strlen(haystack);
// 	result = ft_strnstr(haystack, needle, len);
// 	if (result != NULL)
// 	{
// 		printf("'%s' found at position: %ld\n", needle, result - haystack);
// 	}
// 	else
// 	{
// 		printf("'%s' not found in string.\n", needle);
// 	}
// 	return (0);
// }