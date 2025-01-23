/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:04:56 by ttas              #+#    #+#             */
/*   Updated: 2025/01/23 10:48:03 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/Executor.h"

static char **parsing_echo(char *str)
{
	int i;
	int j;
	char **echo;
	if(ft_strnstr(str, "-n", 2))
	{
		i = 2;
		j = 0;
		echo = malloc(2 * sizeof(char *));
		echo[0] == "-n";
		while(str[i])
		{
			echo[1][j] = str[i];	
			i++;
			j++;
		}
	}
	else
	{
		echo = malloc(2 * sizeof(char *));
		echo[0] = "\0";
		echo[1] = ft_strdup(*str + 2);
	}
	return (echo);
}

void bi_echo(char *str)
{
	int i;
	i = 0;
	char **echo;
	echo = parsing_echo(str);
	if(!fd)
		fd = 1;
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
			ft_printf("%c", echo[1][i]);
			i++;	
		}
	}
	free(echo);
}