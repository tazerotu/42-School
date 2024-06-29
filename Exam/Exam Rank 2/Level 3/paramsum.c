/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:30:06 by marvin            #+#    #+#             */
/*   Updated: 2024/06/29 14:30:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void putnbr(int nbr)
{
	char c;
	if(nbr >= 10)
		putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	if(argc == 1)
		write(1, "0", 1);
	else
	{
		putnbr(argc - 1);
	}
	write(1, "\n", 1);
	return 0;
}