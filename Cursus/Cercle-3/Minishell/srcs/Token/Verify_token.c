/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Verify_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:09:33 by ttas              #+#    #+#             */
/*   Updated: 2025/01/14 10:19:16 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/Minishell.h"

int tokenizer(char *input)
{
	int i;
	i = 0;
	while(input[i])
	{
		// printf("%i,\n", i);
		if(input[i] == 39)
			i = quote(input, i);
		i++;
	}
	return 0;
}

int quote(char *input, int start)
{
	int end;
	end = start;
	// t_splice splice;
	while(input[end] != '\0' || input[end] != 39)
		end++;
	printf("%i\n", end);
	if(input[end] != 39)
		return 0;
	// splice.length = end;
	// splice.str = malloc(end);
	while(start <= end)
	{
	// 	// splice.str[start] = input[start];
		printf("%c", input[start]);
		start++;
	}
	// printf("\n");
	// printf("%s\n", splice.str);
	return end;
}
/*
int d_quote(char *input)
{
	return 0;	
}


int input_redir(char *input)
{
	return 0;
}

int here_doc(char *input)
{
	return 0;
}

int output_redir(char *input)
{
	return 0;
}

int output_append(char *input)
{
	return 0;	
}

int pipe(char *input)
{
	return 0;
}

int logi_and(char *input)
{
	return 0;
}

int logi_or(char *input)
{
	return 0;
}*/