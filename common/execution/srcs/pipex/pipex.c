/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:15 by ttas              #+#    #+#             */
/*   Updated: 2025/06/03 17:05:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

char	*search_path(char **paths, char *cmd)
{
	char	*part_path;
	char	*full_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		if (!part_path)
			return (NULL);
		full_path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (!full_path)
			return (NULL);
		if (access(full_path, F_OK) == 0)
		{
			free_strs(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_strs(paths);
	return (cmd);
}

// Get the path of the command
// If the command is not found, return an error
char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	return (search_path(paths, cmd));
}

void	execute_cmd(t_pipe *pipex)
{
	char	*path;

	if (pipex->cmd->arg_tok != NULL && pipex->cmd->arg_tok[0] != NULL)
	{
		basic_handle_sig(SIGQUIT);
		if (verify_builtin1(pipex) == 1)
		{
			launch_builtin(pipex);
			exit(pipex->exit_status);
		}
		if (ft_strncmp(pipex->cmd->arg_tok[0], "./minishell", 11) == 0)
		{
			if (execve(pipex->cmd->arg_tok[0],
					pipex->cmd->arg_tok, pipex->env) == -1)
				exit(error_message_exec(ERROR_CMD, pipex->cmd->arg_tok[0]));
		}
		path = get_path(pipex->cmd->arg_tok[0], pipex->env);
		if (!path || execve(path, pipex->cmd->arg_tok, pipex->env) == -1)
			exit(error_message_exec(ERROR_CMD, pipex->cmd->arg_tok[0]));
	}
	else
		exit(0);
}

static int ft_wait(t_pipe *pipex, pid_t pid)
{
	int		status;

	pid = wait(&status);
	while (pid > 0)
	{
		pid = wait(&status);
		if (WIFEXITED(status))
			pipex->exit_status = WEXITSTATUS(status);
		init_sigintquit_handling();
	}
	return (pipex->exit_status);
}

int is_exit_command(t_cmd *cmd)
{
	return (cmd && cmd->arg_tok && cmd->arg_tok[0]
		&& ft_strncmp(cmd->arg_tok[0], "exit", 5) == 0
		&& ft_strlen(cmd->arg_tok[0]) == 4);
}

void	pipex(t_pipe *pipex)
{
	t_cmd	*cmd_ptr;
	pid_t	pid;

	pid = 0;
	cmd_ptr = pipex->cmd;
while (cmd_ptr)
{
	if (is_exit_command(cmd_ptr) && (cmd_ptr->next || pipex->prev_fd != -1))
	{
		cmd_ptr = cmd_ptr->next;
		continue;
	}
	if (verify_builtin2(cmd_ptr) == 1)
		launch_builtin(pipex);
	else
		do_pipe(pipex, cmd_ptr, &pipex->prev_fd, pid);
	cmd_ptr = cmd_ptr->next;
}
	pipex->exit_status = ft_wait(pipex, pid);
}
