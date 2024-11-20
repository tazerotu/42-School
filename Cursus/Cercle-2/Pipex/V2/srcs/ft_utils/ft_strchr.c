/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:05:04 by ttas              #+#    #+#             */
/*   Updated: 2024/09/24 09:00:35 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/Pipex.h"

char	*ft_strchr(char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (c > 256)
		c -= 256;
	while (*str != c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strchr("Ceci est un message", 's'));
// 	printf("%s", strchr("Ceci est un message", 's'));
// 	return (0);
// }
