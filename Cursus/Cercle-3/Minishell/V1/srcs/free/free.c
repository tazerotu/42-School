/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:23:16 by ttas              #+#    #+#             */
/*   Updated: 2025/03/20 10:15:23 by ttas             ###   ########.fr       */
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
		free(pipe->envp);
		pipe->envp = tmp;
	}
	free(pipe->envp);
	free(pipe);
}

void	free_env(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		free(env[i]);
	free(env);
}
