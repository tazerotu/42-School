/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:06:32 by ttas              #+#    #+#             */
/*   Updated: 2024/10/24 08:52:30 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	printf("le message est: ceci est un message de 73 characteres\n\n");
	int i = ft_strlen("ceci est un message de 37 characteres");
	printf("le nombres de characteres est de : %d characteres\n", i);
	return (0);
} */
