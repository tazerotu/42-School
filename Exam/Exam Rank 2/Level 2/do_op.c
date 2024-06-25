/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:03:20 by marvin            #+#    #+#             */
/*   Updated: 2024/06/17 09:03:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int ac, char **av)
{
	if(ac < 4 || ac > 4)
		write(1, "\n", 1);
	else
	{
		int num1;
		int num2;
		int result;
		num1 = atoi(av[1]);
		num2 = atoi(av[3]);
		if(av[2][0] == '+')
		{
			result = num1 + num2;
			printf("%d", result);
		}
		else if(av[2][0] == '-')
		{
			result = num1 - num2;
			printf("%d", result);
		}
		else if(av[2][0] == '*')
			printf("%d", (num1 * num2));
		else if(av[2][0] == '/')
		{
			result = num1 / num2;
			printf("%d", result);
		}
		printf("\n");
	}
	return (0);
}