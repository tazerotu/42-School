/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:46:29 by ttas              #+#    #+#             */
/*   Updated: 2024/03/26 10:05:38 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

int	ft_str_is_alpha(char *str)
{
	int	count;
	int	alphabet;

	alphabet = 1;
	count = 0;
	if (str[count] == '\0')
		return (alphabet);
	while (str[count] != '\0')
	{
		if ((str[count] < 'A' || str[count] > 'Z') && (str[count] < 'a'
				|| str[count] > 'z'))
		{
			return (0);
		}
		count++;
	}
	return (alphabet);
}
