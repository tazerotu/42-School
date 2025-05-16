/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putHexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 11:21:32 by ttas              #+#    #+#             */
/*   Updated: 2024/05/13 14:04:41 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// static int	ft_hex_len(unsigned int n)
// {
// 	int	len;

// 	len = 0;
// 	while (n > 15)
// 	{
// 		n = n / 16;
// 		len++;
// 	}
// 	len++;
// 	return (len);
// }

int	ft_hexa(unsigned int decimal_number, char *base)
{
	unsigned int	i;

	i = 0;
	if (decimal_number >= 16)
	{
		i += ft_hexa(decimal_number / 16, base);
	}
	ft_putchar(base[decimal_number % 16]);
	i++;
	return (i);
}

// int	ft_uhexa(unsigned int decimal_number)
// {
// 	int		i;
// 	char	*hexa_number;
// 	int		j;
// 	int		temp;

// 	i = 1;
// 	hexa_number = malloc(ft_hexa_len(decimal_number) + 1);
// 	while (decimal_number != 0)
// 	{
// 		temp = decimal_number % 16;
// 		if (temp < 10)
// 			temp = temp + 48;
// 		else
// 			temp = temp + 55;
// 		hexa_number[i++] = temp;
// 		decimal_number = decimal_number / 16;
// 	}
// 	j = i - 1;
// 	while (j > 0)
// 	{
// 		ft_putchar(hexa_number[j]);
// 		j--;
// 	}
// 	return (i);
// }
