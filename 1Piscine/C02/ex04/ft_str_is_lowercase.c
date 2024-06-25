/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:03:44 by ttas              #+#    #+#             */
/*   Updated: 2024/03/22 12:13:49 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	count;
	int	lowercase;

	lowercase = 1;
	count = 0;
	if (str[count] == '\0')
		return (lowercase);
	while (str[count] != '\0')
	{
		if ((str[count] < 'a' || str[count] > 'z'))
		{
			return (0);
		}
		count++;
	}
	return (lowercase);
}
