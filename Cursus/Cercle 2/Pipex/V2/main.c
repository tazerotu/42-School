/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/08/01 09:25:29 by ttas              #+#    #+#             */
/*   Updated: 2024/08/01 09:25:29 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Includes/Pipex.h"


void	ft_init_pipex(int argc, char **argv, t_ppx *pipex)
{
	get_input_fd(argv, pipex);
	get_output_fd(argv[argc - 1], pipex);
	pipex->cmd_count = argc - 3 - pipex->here_doc;
}

void	child_proccess(char *cmd, char **envp, int inputfd)
{
	pid_t pid;
	int pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT);
		if (inputfd == STDIN)
			exit(1);
		else
			execute(cmd, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_ppx *pipex;
	pipex = NULL;
	int i;
	i = 0;

	if (argc < args_in(argv[1], pipex))
		return (error(INVALID_INPUT));
	ft_init_pipex(argc, argv, pipex);
	dup2(pipex->input_fd, STDIN);
	dup2(pipex->output_fd, STDOUT);
	child_proccess(argv[2], envp, pipex->input_fd);
	while (pipex->cmd[i])
	{
		child_proccess(pipex->cmd[i], envp, 1);
		i++;
	}
	child_proccess(argv[argc - 2], envp, pipex->input_fd);
	return (0);
}
