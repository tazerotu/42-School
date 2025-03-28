/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:13 by ttas              #+#    #+#             */
/*   Updated: 2025/03/28 15:30:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

char	*here_doc(t_pipe *pipe, char *delimiter)
{
	char	*heredoc;
	char	*buffer;
	char	*tmp;

	tmp = NULL;
	heredoc = NULL;
	buffer = get_next_line(STDIN_FILENO);
	while (ft_strnstr(buffer, delimiter, ft_strlen(delimiter)) == NULL)
	{
		expander(buffer, pipe)
		tmp = ft_strjoin(heredoc, buffer);
		free(buffer);
		if (heredoc)
			free(heredoc);
		heredoc = ft_strjoin(heredoc, tmp);
		free(tmp);
		buffer = get_next_line(STDIN_FILENO);
	}
	free(buffer);
	return (heredoc);
}
