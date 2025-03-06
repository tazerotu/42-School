/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:06:28 by ttas              #+#    #+#             */
/*   Updated: 2025/02/27 15:23:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/Executor.h"

// t_pipe *init(t_pipe *pipe, char *str, char **envp)
// {
// 	pipe->n_pipe = 0;
// 	return (pipe);
// }

t_pipe *init_env(t_pipe *pipex, char **envp)
{
	int i;
	i = 1;
	pipex->envp = malloc(sizeof(t_env *));
	pipex->envp = env_new(envp[0]);
	while (envp[i])
	{
		env_add_back(pipex->envp, env_new(envp[i]));
		i++;
	}
	return(pipex);
}