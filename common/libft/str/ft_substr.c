/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:20:17 by ttas              #+#    #+#             */
/*   Updated: 2025/03/05 13:07:38 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (s == 0)
		return (0);
	if (s_len == 0 || len == 0 || start > s_len)
		return (ft_strdup(""));
	if ((start + len > s_len))
		len = s_len - start;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (i < len && s[i + start])
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// int	main(void)
// {
// 	printf("%s", ft_substr("lorem ipsum dolor sit amet", 0, 10));
// 	return (0);
// }
