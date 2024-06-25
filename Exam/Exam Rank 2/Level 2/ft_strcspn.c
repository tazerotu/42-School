/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:43:01 by marvin            #+#    #+#             */
/*   Updated: 2024/06/17 09:43:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	size_t j = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j] && s[i] != reject[j])
		{
			j++;
		}
		if(s[i] == reject[j])
			return (i);
		i++;
	}
	return (i);
}


int main(int ac, char **av) 
{
	if(ac < 3 || ac > 3)
	{
		printf("Usage: ./ft_strcspn string1 string2\n");
		return 1;
	}
	size_t result = ft_strcspn(av[1], av[2]);
	printf("The length of the initial segment of s that does not contain any characters from reject is: %zu\n", result);
	return 0;
}