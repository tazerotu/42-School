/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:37:22 by marvin            #+#    #+#             */
/*   Updated: 2024/06/17 09:37:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strcmp(char *s1, char *s2)
{
	while ((*s1 && *s2) &&*s1 == *s2)
	{
		s1++;
		s2++;
	}
	return(*s1 - *s2);
}

// #include <stdio.h>

// int main(int ac, char **av)
// {
// 	if(ac < 3 || ac > 3)
// 	{
// 		printf("Usage: ./ft_strcmp string1 string2\n");
// 		return 1;
// 	}
// 	int result = ft_strcmp(av[1], av[2]);
	
// 	if (result == 0)
// 	{
// 		printf("%d\n", result);
// 	}
// 	else if (result < 0)
// 	{
// 		printf("%d\n", result);
// 	}
// 	else
// 	{
// 		printf("%d\n", result);
// 	}
	
// 	return 0;
// }