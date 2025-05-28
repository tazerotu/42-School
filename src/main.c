/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:50:26 by ttas              #+#    #+#             */
/*   Updated: 2025/05/28 19:21:25 by clai-ton         ###   ########.fr       */
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
		{
			printf("exit\n");
			exit(0);
		}
		add_history(input);
		if (g_sig_status > 0)
		{
			pipe->exit_status = g_sig_status;
			g_sig_status = 0;
		}
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
	g_sig_status = 0;
	pipe = malloc(sizeof(t_pipe));
	init(pipe, envp);
	init_sigintquit_handling();
	main2(pipe);
	clear_history();
	free_pipe_env(pipe);
	return (0);
}
