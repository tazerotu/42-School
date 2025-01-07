/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:52:44 by ttas              #+#    #+#             */
/*   Updated: 2024/10/24 09:28:13 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/*
int	main(void)
{
	char str1[100] = "ceci est un message", str2[100] = "0123456789",
		str3[100] = "";
	printf("les chaines de caractères sont: \nstr1 : %s \n", str1);
	printf("str2 : %s\nstr3 :%s\n\n", str2, str3);
	int i = ft_str_is_numeric(str1);
	printf("le résultat avec le chaine 1: %d\n", i);
	i = ft_str_is_numeric(str2);
	printf("le résultat avec le chaine 2: %d\n", i);
	i = ft_str_is_numeric(str3);
	printf("le résultat avec le chaine 2: %d\n", i);
	return (0);
}*/