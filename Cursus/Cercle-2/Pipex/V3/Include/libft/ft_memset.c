/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:12:55 by ttas              #+#    #+#             */
/*   Updated: 2024/04/24 08:49:20 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*set;

	set = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		set[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*
int	main(void)
{
	unsigned char str1[11];
	unsigned char str2[11];
	printf("%p\n", ft_memset(&str1, 'g', 11));
	printf("%p", memset(&str2, 'g', 11));
	return (0);
}*/