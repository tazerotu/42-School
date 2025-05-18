/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:15 by ttas              #+#    #+#             */
/*   Updated: 2025/05/17 14:35:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

// Get the path of the command
// If the command is not found, return an error
// char	*get_path(char *cmd, char **envp)
// {
// 	char	**paths;
// 	char	*path;
// 	int		i;
// 	char	*part_path;

// 	i = 0;
// 	while (ft_strnstr(envp[i], "PATH", 4) == 0)
// 		i++;
// 	paths = ft_split(envp[i] + 5, ':');
// 	i = 0;
// 	while (paths[i])
// 	{
// 		part_path = ft_strjoin(paths[i], "/");
// 		path = ft_strjoin(part_path, cmd);
// 		free(part_path);
// 		if (access(path, F_OK) == 0)
// 			return (path);
// 		free(path);
// 		i++;
// 	}
// 	i = -1;
// 	while (paths[++i])
// 		free(paths[i]);
// 	free(paths);
// 	return (0);
// }

// static void	exec(t_pipe *pipex)
// {
// 	char	*path;

// 	if (pipex->cmd)
// 	{
// 		if (verify_builtin(pipex) == 1)
// 		{
// 			launch_builtin(pipex);
// 			exit(0);
// 		}
// 		else
// 		{
// 			path = get_path(pipex->cmd->cmd[0], pipex->env);
// 			if (execve(path, pipex->cmd->cmd, pipex->env) == -1)
// 			{
// 				ft_putstr_fd("command not found: ", 1);
// 				ft_putendl_fd(pipex->cmd->cmd[0], 1);
// 				exit(127);
// 			}
// 		}
// 	}
// }

// static void	do_pipe(t_pipe *pipex)
// {
// 	if (pipe(pipex->pipe_fd) == -1)
// 		return ;
// 	pipex->pid = fork();
// 	if (pipex->pid == -1)
// 		return ;
// 	if (!pipex->pid)
// 	{
// 		close(pipex->pipe_fd[0]);
// 		dup2(pipex->pipe_fd[1], 1);
// 		exec(pipex);
// 	}
// 	else
// 	{
// 		close(pipex->pipe_fd[1]);
// 		dup2(pipex->pipe_fd[0], 0);
// 	}
// }

// void	pipex(t_pipe *pipex)
// {
// 	while (pipex->cmd && pipex->cmd->next)
// 	{
// 		set_redirection(pipex, pipex->cmd->redir);
// 		dup2(pipex->fd_in, 0);
// 		if (pipex->env != NULL)
// 			free_env(pipex->env);
// 		pipex->env = get_env_char(pipex->envp);
// 		do_pipe(pipex);
// 		pipex->cmd = pipex->cmd->next;
// 	}
// 	if (pipex->env != NULL)
// 		free_env(pipex->env);
// 	set_redirection(pipex, pipex->cmd->redir);
// 	pipex->env = get_env_char(pipex->envp);
// 	dup2(pipex->fd_out, 1);
// 	exec(pipex);
// 	free_env(pipex->env);
// }

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_split(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_split(paths);
	return (NULL);
}

static void	execute_cmd(t_pipe *pipex)
{
	char	*path;

	if (pipex->cmd)
	{
		if (verify_builtin(pipex) == 1)
		{
			launch_builtin(pipex);
			exit(0);
		}
		path = get_path(pipex->cmd->cmd[0], pipex->env);
		if (!path || execve(path, pipex->cmd->cmd, pipex->env) == -1)
		{
			ft_putstr_fd("command not found: ", 2);
			ft_putendl_fd(pipex->cmd->cmd[0], 2);
			exit(127);
		}
	}
}

static void	child_process(t_pipe *pipex, int prev_fd, int *pipe_fd)
{
	if (prev_fd != -1)
	{
		dup2(prev_fd, STDIN_FILENO);
		close(prev_fd);
	}
	if (pipex->cmd->next)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}

	set_redirection(pipex, pipex->cmd->redir);

	if (pipex->fd_in != -1)
		dup2(pipex->fd_in, STDIN_FILENO);
	if (pipex->fd_out != -1)
		dup2(pipex->fd_out, STDOUT_FILENO);

	execute_cmd(pipex);
}

static void	parent_cleanup(int *prev_fd, int *pipe_fd)
{
	if (*prev_fd != -1)
		close(*prev_fd);
	if (pipe_fd)
	{
		*prev_fd = pipe_fd[0];
		close(pipe_fd[1]);
	}
}

void	pipex(t_pipe *pipex)
{
	t_cmd	*cmd_ptr;
	int		pipe_fd[2];
	int		prev_fd;
	pid_t	pid;

	cmd_ptr = pipex->cmd;
	prev_fd = -1;
	while (cmd_ptr)
	{
		if (cmd_ptr->next && pipe(pipe_fd) == -1)
			exit(1);
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0)
		{
			pipex->cmd = cmd_ptr;
			pipex->env = get_env_char(pipex->envp);
			child_process(pipex, prev_fd, cmd_ptr->next ? pipe_fd : NULL);
		}
		else
		{
			pipex->pid = pid;
			parent_cleanup(&prev_fd, cmd_ptr->next ? pipe_fd : NULL);
			cmd_ptr = cmd_ptr->next;
		}
	}
	while (wait(NULL) > 0)
		;
}
