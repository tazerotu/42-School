/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:06:28 by ttas              #+#    #+#             */
/*   Updated: 2025/04/30 18:23:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

static void	init_pipe(t_pipe *pipe)
{
	pipe->exit_status = 0;
	pipe->cmd = NULL;
	pipe->envp = NULL;
	pipe->fd_in = 0;
	pipe->fd_out = 1;
}

t_pipe	*init(t_pipe *pipe, char **envp)
{
	init_pipe(pipe);
	init_env(pipe, envp);
	return (pipe);
}

t_pipe	*init_env(t_pipe *pipex, char **envp)
{
	int	i;

	i = 1;
	pipex->envp = env_new(envp[0]);
	while (envp[i])
	{
		env_add_back(pipex->envp, env_new(envp[i]));
		i++;
	}
	return (pipex);
}
