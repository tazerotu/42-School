/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:13 by ttas              #+#    #+#             */
/*   Updated: 2025/06/02 17:10:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

static char	*here_doc_join(char *heredoc, char *buffer, char *tmp)
{
	ft_printf("\033[0;37mheredoc> \033[0m");
	tmp = ft_strjoin(heredoc, buffer);
	free(buffer);
	if (heredoc)
		free(heredoc);
	heredoc = ft_strdup(tmp);
	free(tmp);
	return (heredoc);
}

static char	*get_here_doc(char *heredoc, char *buffer, char *tmp, char *delim)
{
	size_t	len;

	len = ft_strlen(delim);
	buffer = get_next_line(STDIN_FILENO);
	while (!g_sig_status && buffer
		&& !(ft_strnstr(buffer, delim, len) && ft_strlen(buffer) == len + 1))
	{
		heredoc = here_doc_join(heredoc, buffer, tmp);
		buffer = get_next_line(STDIN_FILENO);
	}
	if (!buffer)
		printf("\n");
	free(buffer);
	return (heredoc);
}

static char	*here_doc_expand(t_pipe *pipe, char *heredoc, char *tmp)
{
	if (heredoc)
		tmp = expander(heredoc, pipe->envp, pipe);
	free(heredoc);
	return (tmp);
}

void	here_doc(t_pipe *pipe, char *delim)
{
	char	*heredoc;
	char	*buffer;
	char	*tmp;
	int		fd;

	tmp = NULL;
	heredoc = NULL;
	buffer = NULL;
	heredoc_handle_sigint();
	ignore_sig(SIGQUIT);
	ft_printf("\033[0;37mheredoc> \033[0m");
	heredoc = get_here_doc(heredoc, buffer, tmp, delim);
	tmp = here_doc_expand(pipe, heredoc, tmp);
	fd = open("./tmp/.heredoc.tmp",
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tmp && !g_sig_status)
		ft_fprintf(fd, "%s", tmp);
	close(fd);
	free(tmp);
	if (g_sig_status)
		pipe->exit_status = g_sig_status;
	init_sigintquit_handling();
}
