/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:37:03 by ttas              #+#    #+#             */
/*   Updated: 2025/04/25 09:14:17 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

// Verify if the redirection is valid or not
int	*set_redirection(char **redir)
{
	int	fd[2];
	int	i;

	i = 0;
	fd[0] = -1;
	fd[1] = -1;
	if (!redir)
		return (0);
	while (redir[i++])
	{
		if (redir[i][0] == '<')
			fd[0] = set_redir_input(redir, i);
		else if (redir[i][0] == '>')
			fd[1] = set_redir_output(redir, i);
		i++;
	}
	return (fd);
}

int	set_redir_input(char **redir, int i)
{
	int	fd;

	fd = -1;
	if (redir[i][0] == '<')
	{
		if(redir[i][1] == '<')
			fd[1] = open("./srcs/pipex/pipex_utils/.heredoc.tmp", O_RDONLY);
		else
			fd[1] = open(redir[i + 1], O_RDONLY);
		if (fd[1] < 0)
			return (ERROR_FD);
	}
	return (fd);
}

int	set_redir_output(char **redir, int i)
{
	int	fd;

	fd = -1;
	if (redir[i][0] == '>')
	{
		if (redir[i][1] == '>')
			fd[0] = open(redir[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd[0] = open(redir[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[0] < 0)
			return (ERROR_FD);
	}
	return (fd);
}
