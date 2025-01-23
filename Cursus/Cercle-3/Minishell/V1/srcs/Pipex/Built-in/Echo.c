/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:04:56 by ttas              #+#    #+#             */
/*   Updated: 2025/01/23 10:28:06 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/Executor.h"

char **parsing_echo(char *str)
{
	char **echo;
	return (echo);
}

void bi_echo(char *str)
{
	int i;
	i = 0;
	char **echo;
	echo = parsing_echo(str);
	if(echo[0] != "-n")
		ft_printf("%s\n", echo[1]);
	else
	{
		while(echo[1][i])
		{
			if(echo[1][i] == "\n")
			{
				if(echo[1][i+1] != "\0")
					ft_printf(" ");
				i++;
			}	
		}
	}
}