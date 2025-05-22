/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:50:26 by ttas              #+#    #+#             */
/*   Updated: 2025/05/19 21:14:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// static int ft_exit(t_pipe *pipe)
// {
// 	// free_pipe_env(pipe);
// 	// free(pipe);
// 	// exit(0);
// 	return (0);
// }

void	main2(t_pipe *pipe)
{
	char	*input;

	while (1)
	{
		input = readline("\033[0;32mMinishell>\033[0m");
		add_history(input);
		pipe->cmd = process_line(input, pipe);
		pipex(pipe);
		free(input);
		free_cmds(pipe->cmd);
		pipe->cmd = NULL;
		if (pipe->exit > 0)
			exit(pipe->exit_status);
			// ft_exit(pipe);
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
