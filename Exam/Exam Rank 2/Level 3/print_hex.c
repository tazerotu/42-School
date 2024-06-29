/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:03:36 by marvin            #+#    #+#             */
/*   Updated: 2024/06/29 15:03:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str)
{
	int result = 0;
	while (*str)
	{
		result = (result * 10) + (*str - '0'); 
		str++;
	}
	return result;
}



void puthex (int nbr)
{
	char base[16] = "0123456789abcdef";
	if(nbr >= 16)
		puthex(nbr / 16);
	char digit = base[nbr % 16];
	write(1, &digit, 1);
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		puthex(ft_atoi(argv[1]));
	}
	write(1, "\n", 1);
}