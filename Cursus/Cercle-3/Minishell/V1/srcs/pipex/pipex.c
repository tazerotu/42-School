/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:15 by ttas              #+#    #+#             */
/*   Updated: 2025/05/01 18:29:11 by marvin           ###   ########.fr       */
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

void	execute(t_pipe *pipex)
{
	char	*path;

	verify_builtin(pipex);
	if (pipex->exit == 0)
		return;
	path = get_path(pipex->cmd->cmd[0], pipex->env);
	if (!path)
	{
		error_message(127, pipex->cmd->cmd[0]);
		exit(127);
	}
	if (execve(path, pipex->cmd->cmd, pipex->env) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

void	do_pipe(char *cmd, char **env)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		exec(cmd, env);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
	}
}pipex->exit = WEXITSTATUS(pipex->exit_status);
}

void	pipex(t_pipe *pipex)
{
	while (pipex->cmd)
	{
		if (pipe(pipex->pipe_fd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		pipex->pid = fork();
		if (pipex->pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pipex->pid == 0)
			child_process(pipex);
		else
			parent_process(pipex);
		pipex->cmd = pipex->cmd->next;
	}
	free_pipe_env(pipex);
}
