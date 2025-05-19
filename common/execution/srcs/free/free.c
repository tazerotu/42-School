/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:23:16 by ttas              #+#    #+#             */
/*   Updated: 2025/05/19 19:02:36 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

void	free_pipe_env(t_pipe *pipe)
{
	t_env	*tmp;

	while (pipe->envp->previous)
		pipe->envp = pipe->envp->previous;
	while (pipe->envp)
	{
		tmp = pipe->envp->next;
		free(pipe->envp->env);
		free(pipe->envp);
		pipe->envp = tmp;
	}
	free(pipe);
}

void	free_env(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		free(env[i]);
	free(env[i]);
	free(env);
}

// int i;

// i = 0;
// while(cmd->cmd[i])
	// free(cmd->cmd[i++]);
// void	ft_free_cmd(t_cmd *cmd)
// {
// 	free(cmd->arg_tok);
// 	free(cmd);
// }
