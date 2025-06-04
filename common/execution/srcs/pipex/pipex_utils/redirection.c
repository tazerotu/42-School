/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:37:03 by ttas              #+#    #+#             */
/*   Updated: 2025/06/04 10:21:44 by ttas             ###   ########.fr       */
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
			pipe->fd_in = open("./tmp/.heredoc.tmp",
					O_RDONLY, S_IRWXU);
		}
		else
			pipe->fd_in = open(redir[i + 1], O_RDONLY, S_IRWXU);
		if (pipe->fd_in < 0)
		{
			ft_fprintf(2, "minishell: no such file or directory\n");
			exit (1);
		}
	}
	return ;
}

void	set_redir_output(t_pipe *pipe, char **redir, int i)
{
	if (redir[i][0] == '>')
	{
		if (redir[i][1] == '>')
			pipe->fd_out = open(redir[i + 1], O_WRONLY
					| O_CREAT | O_APPEND, S_IRWXU);
		else
			pipe->fd_out = open(redir[i + 1], O_WRONLY
					| O_CREAT | O_TRUNC, S_IRWXU);
		if (pipe->fd_out < 0)
		{
			ft_fprintf(2, "minishell: Error when opening file or directory\n");
			exit (1);
		}
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
	while (redir[i])
	{
		if (redir[i][0] == '<')
		{
			ft_close(pipe->fd_in);
			set_redir_input(pipe, redir, i);
		}
		else if (redir[i][0] == '>')
		{
			ft_close(pipe->fd_out);
			set_redir_output(pipe, redir, i);
		}
		i++;
	}
	return ;
}
