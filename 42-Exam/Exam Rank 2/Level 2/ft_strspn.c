/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:59:18 by marvin            #+#    #+#             */
/*   Updated: 2024/06/17 14:59:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	unsigned int i = 0, j;
	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if(s[i] != accept[j])
				return (i);
			j++;
		}
		i++;
	}
	
	return (i);
}