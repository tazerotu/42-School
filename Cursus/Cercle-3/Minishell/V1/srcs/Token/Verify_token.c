/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Verify_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:09:33 by ttas              #+#    #+#             */
/*   Updated: 2025/01/14 11:25:03 by ttas             ###   ########.fr       */
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
			i = quote(input, (i+1));
		i++;
	}
	return 0;
}

int quote(char *input, int start)
{
	int end;
	int i;
	t_splice splice;
	i = 0;
	end = start;
	while(input[end])
		end++;
	if(input[end-1] == 39)
		end--;
	splice.length = (end - start);
	splice.str = malloc(splice.length * sizeof(char *) + 1);
	while(start <= splice.length)
	{
		splice.str[i] = input[start];
		start++;
		i++;
	}
	splice.str[i] = '\0';
	printf("Splice :\n\tlength : %i\n\tstr : %s\n", splice.length, splice.str);
	if(input[end] == '\0')
		end--;
	return (end);
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