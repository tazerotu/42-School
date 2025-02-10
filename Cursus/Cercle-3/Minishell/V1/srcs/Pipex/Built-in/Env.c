/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:04:54 by ttas              #+#    #+#             */
/*   Updated: 2025/02/10 20:55:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/Executor.h"

void bi_env(t_pipe *pipex, char **envp)
{
	int i;
	i = 1;
	pipex->envp = env_new(envp[0]);
	while (envp[i])
	{
		env_add_back(pipex->envp, env_new(envp[i]));
		i++;
	}
}