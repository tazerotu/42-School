/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:14:39 by ttas              #+#    #+#             */
/*   Updated: 2024/04/24 09:07:43 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
	{
		return (1);
	}
	return (0);
}

/*
int	main(void)
{
	char str1[100] = "abcdefghijklmnopqrstuvwxyz", str2[100] = "0123456789",
		str3[100] = "", str4[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("les chaines de caractères sont: \nstr1 : %s \n", str1);
	printf("str2 : %s\nstr3 :%s\nstr4 : %s\n\n", str2, str3, str4);
	int i = ft_str_is_printable(str1);
	printf("le résultat avec le chaine 1: %d\n", i);
	i = ft_str_is_printable(str2);
	printf("le résultat avec le chaine 2: %d\n", i);
	i = ft_str_is_printable(str3);
	printf("le résultat avec le chaine 3: %d\n", i);
	i = ft_str_is_printable(str4);
	printf("le résultat avec le chaine 4: %d\n", i);
	return (0);
}*/