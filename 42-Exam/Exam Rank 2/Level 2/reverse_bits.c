/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:28:39 by marvin            #+#    #+#             */
/*   Updated: 2024/06/17 15:28:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

unsigned char reverse_bits(unsigned char octet)
{
	unsigned char reversed = 0;
	int i;
	while(i < 8)
	{
		reversed = (reversed << 1) | (octet & 1);
		octet >>= 1;
		i++;
	}
	return reversed;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <number>\n", argv[0]);
		return 1;
	}

	unsigned char octet = atoi(argv[1]);
	unsigned char reversed = reverse_bits(octet);
	printf("Reversed bits: %u\n", reversed);

	return 0;
}