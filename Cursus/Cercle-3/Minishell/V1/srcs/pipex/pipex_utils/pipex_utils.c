/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:03:22 by ttas              #+#    #+#             */
/*   Updated: 2025/05/05 09:40:54 by ttas             ###   ########.fr       */
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

// void	start_pipe(t_pipe *pipe)
// {
// 	if (pipe(pipe->fds) == -1)
// 	{
// 		perror("pipe");
// 		exit(EXIT_FAILURE);
// 	}
// }

// void	close_pipe(t_pipe *pipe)
// {
// 	if (pipe->fd_in)
// 		close(pipe->fd_in);
// 	if (pipe->fd_out)
// 		close(pipe->fd_out);
// }
