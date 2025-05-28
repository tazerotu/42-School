/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:15 by ttas              #+#    #+#             */
/*   Updated: 2025/05/28 14:47:33 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

// Get the path of the command
// If the command is not found, return an error
char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	execute_cmd(t_pipe *pipex)
{
	char	*path;

	if (pipex->cmd)
	{
		basic_handle_sig(SIGQUIT);
		if (verify_builtin1(pipex) == 1)
		{
			launch_builtin(pipex);
			exit(pipex->exit_status);
		}
		if (ft_strncmp(pipex->cmd->arg_tok[0], "./Minishell", 10) == 0)
		{
			if (execve(pipex->cmd->arg_tok[0],
					pipex->cmd->arg_tok, pipex->env) == -1)
				exit(error_message_exec(ERROR_CMD, pipex->cmd->arg_tok[0]));
		}
		path = get_path(pipex->cmd->arg_tok[0], pipex->env);
		if (!path || execve(path, pipex->cmd->arg_tok, pipex->env) == -1)
			exit(error_message_exec(ERROR_CMD, pipex->cmd->arg_tok[0]));
	}
}

void	pipex(t_pipe *pipex)
{
	t_cmd	*cmd_ptr;
	int		prev_fd;
	int		status;
	pid_t	pid;

	cmd_ptr = pipex->cmd;
	prev_fd = -1;
	while (cmd_ptr)
	{
		if (verify_builtin2(cmd_ptr) == 1)
			launch_builtin(pipex);
		else
			do_pipe(pipex, cmd_ptr, &prev_fd);
		cmd_ptr = cmd_ptr->next;
	}
	pid = wait(&status);
	while (pid > 0)
	{
		pid = wait(&status);
		if (WIFEXITED(status))
			pipex->exit_status = WEXITSTATUS(status);
		init_sigintquit_handling();
	}
}
