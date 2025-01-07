/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:28:51 by ttas              #+#    #+#             */
/*   Updated: 2025/01/07 10:29:55 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Minishell.h"

int main(void)
{
        char *inpt;

        int i = 0;

        while ( i < 10 )
        {
                inpt = readline("");
                add_history(inpt);
                printf("%s", inpt);
                int i = strlen(inpt);
                int j = 0;
                while(j <= i)
                {
                        
                        j++;
                }
                printf("\n");
                ++i;
        }
	return (0);
}