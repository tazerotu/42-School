/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:03:22 by ttas              #+#    #+#             */
/*   Updated: 2025/06/01 21:22:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

void	ft_close(int fd)
{
	if (fd)
		close(fd);
}

int	cmd_count(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		cmd = cmd->next;
		i++;
	}
	return (i);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	child_process(t_pipe *pipex, int prev_fd, int *pipe_fd)
{
	set_redirection(pipex, pipex->cmd->redir_tok);
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
	if (pipex->fd_in != -1)
		dup2(pipex->fd_in, STDIN_FILENO);
	if (pipex->fd_out != -1)
		dup2(pipex->fd_out, STDOUT_FILENO);
	execute_cmd(pipex);
}

void	parent_cleanup(int *prev_fd, int *pipe_fd)
{
	if (*prev_fd != -1)
		close(*prev_fd);
	if (pipe_fd)
	{
		*prev_fd = pipe_fd[0];
		close(pipe_fd[1]);
	}
}
