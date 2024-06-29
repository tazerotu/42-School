/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:21:48 by marvin            #+#    #+#             */
/*   Updated: 2024/06/29 14:21:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
	int i;
	if(b > a)
		i = b;
	else
		i = a;
	while ((i % a) != 0 || (i % b) != 0)
	{
		i++;
	}
	return i;
}

int main()
{
    unsigned int a = 12;
    unsigned int b = 18;
    printf("LCM of %u and %u is %u\n", a, b, lcm(a, b));
    
    a = 21;
    b = 6;
    printf("LCM of %u and %u is %u\n", a, b, lcm(a, b));
    
    a = 8;
    b = 32;
    printf("LCM of %u and %u is %u\n", a, b, lcm(a, b));

    a = 7;
    b = 3;
    printf("LCM of %u and %u is %u\n", a, b, lcm(a, b));

    return 0;
}