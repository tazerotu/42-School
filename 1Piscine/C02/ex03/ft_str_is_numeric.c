/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:52:44 by ttas              #+#    #+#             */
/*   Updated: 2024/03/22 12:12:31 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	count;
	int	numeric;

	numeric = 1;
	count = 0;
	if (str[count] == '\0')
		return (numeric);
	while (str[count] != '\0')
	{
		if ((str[count] < 47 || str[count] > 58))
		{
			return (0);
		}
		count++;
	}
	return (numeric);
}
