/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:15 by ttas              #+#    #+#             */
/*   Updated: 2025/05/28 11:04:17 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

// Get the path of the command
// If the command is not found, return an error
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
	return (NULL);
}

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

	if (pipex->cmd)
	{
		if (verify_builtin1(pipex) == 1)
		{
			launch_builtin(pipex);
			exit(pipex->exit_status);
		}
		if (ft_strncmp(pipex->cmd->arg_tok[0], "./Minishell", 10) == 0)
		{
			if (execve(pipex->cmd->arg_tok[0],
					pipex->cmd->arg_tok, pipex->env) == -1)
			{
				error_message_exec(ERROR_CMD, pipex->cmd->arg_tok[0]);
				exit(127);
			}
		}
		path = get_path(pipex->cmd->arg_tok[0], pipex->env);
		if (!path || execve(path, pipex->cmd->arg_tok, pipex->env) == -1)
		{
			error_message_exec(ERROR_CMD, pipex->cmd->arg_tok[0]);
			exit(127);
		}
	}
}

static void	do_pipe(t_pipe *pipex, t_cmd *cmd_ptr, int *prev_fd)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (cmd_ptr->next && pipe(pipe_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		pipex->cmd = cmd_ptr;
		pipex->env = get_env_char(pipex->envp);
		if (cmd_ptr->next)
			child_process(pipex, *prev_fd, pipe_fd);
		else
			child_process(pipex, *prev_fd, NULL);
	}
	else
	{
		pipex->pid = pid;
		if (cmd_ptr->next)
			parent_cleanup(prev_fd, pipe_fd);
		else
			parent_cleanup(prev_fd, NULL);
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
	}
}
