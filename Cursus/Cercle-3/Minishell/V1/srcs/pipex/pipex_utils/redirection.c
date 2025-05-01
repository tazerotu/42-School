/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:37:03 by ttas              #+#    #+#             */
/*   Updated: 2025/05/01 11:23:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

void	set_redir_input(t_pipe *pipe, char **redir, int i)
{

	if (redir[i][0] == '<')
	{
		if (redir[i][1] == '<')
		{
			here_doc(pipe, redir[i + 1]);
			pipe->fd_in = open("./srcs/pipex/pipex_utils/.heredoc.tmp", O_RDONLY, S_IRWXU);
		}
		else
			pipe->fd_in = open(redir[i + 1], O_RDONLY, S_IRWXU);
		if (pipe->fd_in < 0)
			return ;
	}
	return ;
}

void	set_redir_output(t_pipe *pipe, char **redir, int i)
{
	if (redir[i][0] == '>')
	{
		if (redir[i][1] == '>')
			pipe->fd_out = open(redir[i + 1], O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
		else
			pipe->fd_out = open(redir[i + 1], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
		if (pipe->fd_out < 0)
			return ;
	}
	return ;
}

// Verify if the redirection is valid or not
void	set_redirection(t_pipe *pipe, char **redir)
{
	int	i;

	i = 0;
	if (!redir)
		return ;
	while (redir[i++])
	{
		if (redir[i][0] == '<')
		{
			close(pipe->fd_in);
			set_redir_input(pipe, redir, i);
		}
		else if (redir[i][0] == '>')
		{
			close(pipe->fd_out);
			set_redir_output(pipe, redir, i);
		}
		i++;
	}
	return ;
}

int	set_pipex(t_pipe *pipex)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		if(pipefd[1] > 0)
			close(pipefd[1]);
		dup2(pipefd[0], STDIN);
		pipex->fd_in = pipefd[0];
		pipex->pid = -1;
		return (2);
	}
	else
	{
		if(pipefd[0] > 0)
			close(pipefd[0]);
		dup2(pipefd[1], STDOUT);
		pipex->fd_out = pipefd[1];
		pipex->pid = pid;
		return (1);
	}
}
