/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:38:47 by marvin            #+#    #+#             */
/*   Updated: 2024/06/29 14:38:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        long l1 = atol(argv[1]);
        long l2 = atol(argv[2]);

        if (l1 >= 2147483648 || l1 < -2147483648 || l2 >= 2147483648 || l2 < -2147483648)
        {
            printf("\n");
            return 0;
        }

        int i;
        for (i = 2; i <= l1 && i <= l2; i++)
        {
            if (l1 % i == 0 && l2 % i == 0)
            {
                printf("%d\n", i);
                return 0;
            }
        }
    }
    else
    {
        printf("\n");
    }
    return 0;
}