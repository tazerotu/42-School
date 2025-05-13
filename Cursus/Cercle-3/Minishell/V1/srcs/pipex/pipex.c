/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:15 by ttas              #+#    #+#             */
/*   Updated: 2025/05/13 18:38:15 by marvin           ###   ########.fr       */
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

static void	exec(t_pipe *pipex)
{
	char	*path;

	if(pipex->cmd)
	{
		if(verify_builtin(pipex) == 0)
		{
			path = get_path(pipex->cmd->cmd[0], pipex->env);
			if (execve(path, pipex->cmd->cmd, pipex->env) == -1)
			{
				ft_putstr_fd("command not found: ", 1);
				ft_putendl_fd(pipex->cmd->cmd[0], 1);
			}
		}
		
	}
}

static void	do_pipe(t_pipe *pipex)
{
	if (pipe(pipex->pipe_fd) == -1)
		return ;
	pipex->pid = fork();
	if (pipex->pid == -1)
		return ;
	if (!pipex->pid)
	{
		close(pipex->pipe_fd[0]);
		dup2(pipex->pipe_fd[1], 1);
		exec(pipex);
	}
	else
	{
		close(pipex->pipe_fd[1]);
		dup2(pipex->pipe_fd[0], 0);
	}
}

void	pipex(t_pipe *pipex)
{
	while (pipex->cmd && pipex->cmd->next)
	{
		set_redirection(pipex, pipex->cmd->redir);
		dup2(pipex->fd_in, 0);
		if (pipex->env != NULL)
			free_env(pipex->env);
		pipex->env = get_env_char(pipex->envp);
		do_pipe(pipex);
		pipex->cmd = pipex->cmd->next;
	}
	if (pipex->env != NULL)
		free_env(pipex->env);
	set_redirection(pipex, pipex->cmd->redir);
	pipex->env = get_env_char(pipex->envp);
	dup2(pipex->fd_out, 1);
	exec(pipex);
	free_env(pipex->env);
}

// void	execute(t_pipe *pipex)
// {
// 	char	*path;

// 	if (verify_builtin(pipex))
// 		return ;
// 	else
// 	{
// 		if (pipex->exit == 0)
// 			return;
// 		path = get_path(pipex->cmd->cmd[0], pipex->env);
// 		if (!path)
// 		{
// 			error_message(127, pipex->cmd->cmd[0]);
// 			exit(127);
// 		}
// 		if (execve(path, pipex->cmd->cmd, pipex->env) == -1)
// 		{
// 			perror("execve");
// 			exit(EXIT_FAILURE);
// 		}
// 	}
// }

// void	do_pipe(t_pipe *pipex)
// {
// 	if (pipe(pipex->pipe_fd) == -1)
// 		exit(0);
// 	pipex->pid = fork();
// 	if (pipex->pid == -1)
// 		exit(0);
// 	if (pipex->pid == 0)
// 	{
// 		ft_close(pipex->pipe_fd[0]);
// 		dup2(pipex->pipe_fd[1], 1);
// 		execute(pipex);
// 		ft_printf("C1\n");	
// 	}
// 	else
// 	{
// 		ft_close(pipex->pipe_fd[1]);
// 		dup2(pipex->pipe_fd[0], 0);
// 		ft_printf("C2\n");
// 	}
// 	pipex->exit = WEXITSTATUS(pipex->exit_status);
// }

// void	pipex(t_pipe *pipex)
// {
// 	while (pipex->cmd && pipex->cmd->next)
// 	{
// 		set_redirection(pipex, pipex->cmd->redir);
// 		if(pipex->fd_in == 0)
// 			dup2(pipex->fd_in, 0);
// 		pipex->env = get_env_char(pipex->envp, pipex->env);
// 		do_pipe(pipex);
// 		ft_printf("%s\n", pipex->cmd->cmd[0]);
// 		pipex->cmd = pipex->cmd->next;
// 	}
// 	ft_printf("%s\n", pipex->cmd->cmd[0]);
// 	pipex->env = get_env_char(pipex->envp, pipex->env);
// 	dup2(pipex->fd_out, 1);
// 	execute(pipex);
// 	free_env(pipex->env);
// 	ft_free_cmd(pipex->cmd);
// }
