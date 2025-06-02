/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:06:28 by ttas              #+#    #+#             */
/*   Updated: 2025/06/02 17:24:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

static void	init_pipe(t_pipe *pipe)
{
	pipe->exit_status = 0;
	pipe->exit = 0;
	pipe->cmd = NULL;
	pipe->env = NULL;
	pipe->fd_in = 0;
	pipe->fd_out = 1;
	pipe->prev_fd = -1;
}

t_pipe	*init(t_pipe *pipe, char **envp)
{
	init_pipe(pipe);
	if (!envp || !envp[0])
		pipe->envp = env_new("");
	else
		init_env(pipe, envp);
	return (pipe);
}

t_pipe	*init_env(t_pipe *pipe, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (i == 0)
			pipe->envp = env_new(envp[0]);
		else
			env_add_back(pipe->envp, env_new(envp[i]));
		i++;
	}
	return (pipe);
}
