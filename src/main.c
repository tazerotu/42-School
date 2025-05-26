/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:50:26 by ttas              #+#    #+#             */
/*   Updated: 2025/05/26 13:56:58 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	main2(t_pipe *pipe)
{
	char	*input;

	while (1)
	{
		input = readline("\033[0;32mMinishell>\033[0m");
		if (!input)
			exit(0);
		add_history(input);
		pipe->cmd = process_line(input, pipe);
		pipex(pipe);
		free(input);
		free_cmds(pipe->cmd);
		pipe->cmd = NULL;
		if (pipe->exit > 0)
			exit(pipe->exit_status);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*pipe;

	(void) argc;
	(void) argv;
	pipe = malloc(sizeof(t_pipe));
	init(pipe, envp);
	main2(pipe);
	clear_history();
	free_pipe_env(pipe);
	return (0);
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
