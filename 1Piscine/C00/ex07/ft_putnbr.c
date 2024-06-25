/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:27:52 by ttas              #+#    #+#             */
/*   Updated: 2024/03/21 09:37:57 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	string_length(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	int_to_string(int nb, char *buffer)
{
	int	temp;
	int	i;
	int	num_digits;

	if (nb == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return ;
	}
	num_digits = 0;
	temp = nb;
	while (temp != 0)
	{
		temp /= 10;
		num_digits++;
	}
	i = num_digits - 1;
	buffer[num_digits] = '\0';
	while (i >= 0)
	{
		buffer[i] = '0' + (nb % 10);
		nb /= 10;
		i--;
	}
}

void	ft_putnbr(int nb)
{
	char	buffer[20];
	int		len;
	int		negatif;
	char	c;

	negatif = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			negatif = 1;
		}
		int_to_string(nb, buffer);
		len = string_length(buffer);
		if (negatif == 1)
		{
			c = '-';
			write(1, &c, 1);
		}
		write(1, buffer, len);
	}
}
