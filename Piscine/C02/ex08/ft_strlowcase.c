/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 09:22:14 by ttas              #+#    #+#             */
/*   Updated: 2024/03/27 11:16:38 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	count;

	count = 0;
	if (str[count] == '\0')
		return (str);
	while (str[count] != '\0')
	{
		if ((str[count] > 96 && str[count] < 123))
		{
			str[count] = str[count] - 32;
		}
		count++;
	}
	return (str);
}
