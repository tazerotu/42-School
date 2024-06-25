/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:51:38 by marvin            #+#    #+#             */
/*   Updated: 2024/06/17 09:51:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(char *src)
{
	int i = 0;
	while (src[i])
		i++;
	char *new_str;
	new_str = (char *)malloc((i + 1) * sizeof(char));
	if (new_str == NULL) {
		return NULL; // handle memory allocation failure
	}
	i = 0;
	while (src[i])
	{
		new_str[i] = src[i];
		i++;
	}
	return (new_str);
}



int main(int argc, char *argv[]) 
{
	if (argc != 2) {
		printf("Usage: %s <string>\n", argv[0]);
		return 1;
	}
	
	char *src = argv[1];
	char *dup = ft_strdup(src);
	
	printf("Original string: %s\n", src);
	printf("Duplicated string: %s\n", dup);
	
	free(dup);
	
	return 0;
}


