/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:14:39 by ttas              #+#    #+#             */
/*   Updated: 2024/03/22 12:14:33 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	count;
	int	printable;

	printable = 1;
	count = 0;
	if (str[count] == '\0')
		return (printable);
	while (str[count] != '\0')
	{
		if ((str[count] < 32 || str[count] > 127))
		{
			return (0);
		}
		count++;
	}
	return (printable);
}
