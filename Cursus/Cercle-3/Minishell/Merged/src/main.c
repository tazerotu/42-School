/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:50:26 by ttas              #+#    #+#             */
/*   Updated: 2025/05/14 09:51:52 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void main2(char **envp)
{
	
}

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	/* init */
	
}




// Main
/* Readline
	int i = 0;
	char *input;
	while ( i < 10 )
{
    input = readline("\033[0;32mMinishell>\033[0m");
    add_history(input);
	ft_printf("%s\n", input);
	free(input);
	i++;
}
*/


// int execution(int argc, char **argv, char **envp)
// {
// 	(void)argc;
// 	(void)argv;
//     system("clear");
// 	t_pipe *pipe;
// 	pipe = malloc(sizeof(t_pipe));
// 	init(pipe, envp);
// 	// test_pipex(pipe);
// 	free_pipe_env(pipe);
// 	return(0);
// }