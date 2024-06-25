/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:31:21 by marvin            #+#    #+#             */
/*   Updated: 2024/06/17 09:31:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(const char *str)
{
	int signe = 1;
	int result = 0;
	while (*str)
	{
		if(*str == '+' || *str == '-')
		{
			if(*str == '-')
				signe = -1;
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			result = (result * 10) + (*str - '0');
			str++;
		}
	}
	return (result * signe);
}
