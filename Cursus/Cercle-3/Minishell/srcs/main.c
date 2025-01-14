/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:28:51 by ttas              #+#    #+#             */
/*   Updated: 2025/01/14 12:05:36 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Minishell.h"

int main(void)
{
        char *input;

        int i = 0;
        system("clear");
        while ( i < 10 )
        {
                input = readline("\033[0;32mMinishell>\033[0m");
                add_history(input);
                tokenizer(input);
                // splicer(input);
                i++;
        }
	return (0);
}