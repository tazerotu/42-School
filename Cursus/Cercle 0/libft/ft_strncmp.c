/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:35:25 by ttas              #+#    #+#             */
/*   Updated: 2024/04/24 10:50:09 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}
/*
int	main(void)
{
	char s1[100] = "ceci est un message", s2[100] = "ceci est Un message";
	int result = 0;
	unsigned int i = 25;
	printf("les messages sont\nMessage 1 : %s\nMessage 2 : %s\n\n", s1, s2);
	result = ft_strncmp(s1, s2, i);
	printf("La difference Ascii est : %d\n", result);
	printf("Reference : %d", strncmp(s1, s2, i));
}*/