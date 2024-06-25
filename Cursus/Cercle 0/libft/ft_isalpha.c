/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:46:29 by ttas              #+#    #+#             */
/*   Updated: 2024/04/23 11:34:14 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}
/*
int	main(void)
{
	char str1[100] = "ceciestunmessage", str2[100] = "0123456789";
	printf("les chaines de caractères sont: \nstr1 : %s \nstr2 : %s\n\n", str1,
		str2);
	int i = ft_str_is_alpha(str1);
	printf("le résultat avec le chaine 1: %d\n", i);
	i = ft_str_is_alpha(str2);
	printf("le résultat avec le chaine 2: %d\n", i);
	return (0);
}*/