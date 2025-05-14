/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:20:17 by ttas              #+#    #+#             */
/*   Updated: 2024/10/24 08:52:47 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (s == 0)
		return (0);
	if (ft_strlen(s) == 0 || len == 0 || start > ft_strlen(s))
		return (ft_strdup(""));
	if ((start + len > ft_strlen(s)))
		len = ft_strlen(s) - start;
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
