/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:13 by ttas              #+#    #+#             */
/*   Updated: 2025/04/28 10:58:19 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

static char	*here_doc_join(char *heredoc, char *buffer, char *tmp)
{
	tmp = ft_strjoin(heredoc, buffer);
	free(buffer);
	if (heredoc)
		free(heredoc);
	heredoc = ft_strjoin(heredoc, tmp);
	free(tmp);
	return (heredoc);
}

void	here_doc(t_pipe *pipe, char *delimiter)
{
	char	*heredoc;
	char	*buffer;
	char	*tmp;
	int		fd;

	tmp = NULL;
	heredoc = NULL;
	buffer = get_next_line(STDIN_FILENO);
	while (ft_strnstr(buffer, delimiter, ft_strlen(delimiter)) == NULL)
	{
		ft_printf("\033[0;37mheredoc>\033[0m");
		heredoc = here_doc_join(heredoc, buffer, tmp);
		buffer = get_next_line(STDIN_FILENO);
	}
	free(buffer);
	if (heredoc)
		tmp = expander(heredoc, pipe->envp, pipe);
	free(heredoc);
	fd = open("./srcs/pipex/pipex_utils/.heredoc.tmp",
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tmp)
		ft_fprintf(fd, "%s", tmp);
	close(fd);
	free(tmp);
	return ;
}
