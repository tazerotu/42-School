/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:15 by ttas              #+#    #+#             */
/*   Updated: 2025/05/21 20:17:47 by marvin           ###   ########.fr       */
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
		if (verify_builtin1(pipex) == 1)
		{
			launch_builtin(pipex);
			exit(pipex->exit_status);
		}
		if(ft_strncmp(pipex->cmd->arg_tok[0], "./Minishell", 10) == 0)
		{
			if(execve(pipex->cmd->arg_tok[0], 
				pipex->cmd->arg_tok, pipex->env) == -1)
			{
				ft_fprintf(2, "1 command not found: %s\n", pipex->cmd->arg_tok[0]);
				exit(127);
			}
		}
		path = get_path(pipex->cmd->arg_tok[0], pipex->env);
		if (!path || execve(path, pipex->cmd->arg_tok, pipex->env) == -1)
		{
			ft_fprintf(2, "command not found: %s\n", pipex->cmd->arg_tok[0]);
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
		child_process(pipex, *prev_fd, cmd_ptr->next ? pipe_fd : NULL);
	}
	else
	{
		pipex->pid = pid;
		parent_cleanup(prev_fd, cmd_ptr->next ? pipe_fd : NULL);
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

	// Wait for all children and get the last exit status
	while ((pid = wait(&status)) > 0)
	{
		if (WIFEXITED(status))
			pipex->exit_status = WEXITSTATUS(status);
	}
}
