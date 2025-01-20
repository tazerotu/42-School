/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:06:28 by ttas              #+#    #+#             */
/*   Updated: 2025/01/20 12:55:05 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/Executor.h"

t_pipe init(t_pipe pipe, char *str, char **envp)
{
	int i = 0;
	pipe.n_pipe = 0;
	while(str[i])
	{
		if(str[i] == '|')
			pipe.n_pipe++;
		i++;
	}
	pipe.n_pipe++;
	pipe.cmd = ft_split(str, '|');
	pipe.envp = envp;
	return (pipe);
}

// t_splice *splicer(t_pipe pipe, char *str)
// {
// 	t_splice *splice;
// 	int i;
// 	int end;
// 	char **split;
// 	end = 0;
// 	i = 0;
// 	while(str[i])
// 	{
// 		if(str[i] == '|')
// 			pipe.n_pipe++;
// 		i++;
// 	}
// 	i = 0;
// 	splice = malloc(pipe.n_pipe * sizeof(t_splice));
// 	split = ft_split(str, '|');
// 	while(split[i])
// 	{
// 		while(split[i][end])
// 			end++;
// 		splice[i].length = end;
// 		splice[i].str = malloc(end * sizeof(char));
// 		splice[i].str = split[i];
// 		i++;
// 	}
// 	return (splice);
// }