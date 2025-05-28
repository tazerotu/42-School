/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:42:06 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/28 14:45:15 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

static void	do_pipe_child(t_pipe *pipex, t_cmd *cmd_ptr,
	int *prev_fd, int *pipe_fd)
{
	init_sigintquit_handling();
	pipex->cmd = cmd_ptr;
	pipex->env = get_env_char(pipex->envp);
	if (cmd_ptr->next)
		child_process(pipex, *prev_fd, pipe_fd);
	else
		child_process(pipex, *prev_fd, NULL);
}

static void	do_pipe_parent(t_pipe *pipex, t_cmd *cmd_ptr,
	int *prev_fd, int *pipe_fd)
{
	init_sigintquit_ignore();
	pipex->pid = pid;
	if (cmd_ptr->next)
		parent_cleanup(prev_fd, pipe_fd);
	else
		parent_cleanup(prev_fd, NULL);
}

void	do_pipe(t_pipe *pipex, t_cmd *cmd_ptr, int *prev_fd)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (cmd_ptr->next && pipe(pipe_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		do_pipe_child(pipex, cmd_ptr, prev_fd, pipe_fd);
	else
		do_pipe_parent(pipex, cmd_ptr, prev_fd, pipe_fd);
}
