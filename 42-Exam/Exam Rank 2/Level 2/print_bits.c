/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:21:53 by marvin            #+#    #+#             */
/*   Updated: 2024/06/17 15:21:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_bits(unsigned char octet)
{
	char c = 0;
	while (octet > 1)
	{
		c = (octet % 2) + '0';
		octet = octet / 2;
		write(1, &c, 1);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "Error: Invalid number of arguments\n", 35);
		return 1;
	}

	unsigned char octet = (unsigned char)atoi(argv[1]);
	print_bits(octet);

	return 0;
}