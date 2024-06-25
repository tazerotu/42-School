/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:12:11 by ttas              #+#    #+#             */
/*   Updated: 2024/03/26 10:06:33 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	count;
	int	uppercase;

	uppercase = 1;
	count = 0;
	if (str[count] == '\0')
		return (uppercase);
	while (str[count] != '\0')
	{
		if ((str[count] < 'A' || str[count] > 'Z'))
		{
			return (0);
		}
		count++;
	}
	return (uppercase);
}
