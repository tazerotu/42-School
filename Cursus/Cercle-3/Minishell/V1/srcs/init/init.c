/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:06:28 by ttas              #+#    #+#             */
/*   Updated: 2025/03/20 10:14:13 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

// t_pipe *init(t_pipe *pipe, char *str, char **envp)
// {
// 	init_env(pipe, envp);
// }

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
