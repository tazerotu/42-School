/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:23:16 by ttas              #+#    #+#             */
/*   Updated: 2025/03/04 11:20:48 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/Executor.h"

void free_all(t_pipe *pipe)
{
	// t_cmd *tmp;
	// t_cmd *tmp2;
	// t_env *prev;

	// tmp = pipe->cmd;
	// while(tmp)
	// {
	// 	tmp2 = tmp->next;
	// 	free(tmp->cmd);
	// 	free(tmp->redir);
	// 	free(tmp);
	// 	tmp = tmp2;
	// }
	// pipe->envp = env_last(pipe->envp);
	// while (pipe->envp->previous)
	// {
	// 	prev = pipe->envp->previous;
	// 	free(pipe->envp->env);
	// 	free(pipe->envp);
	// 	pipe->envp = prev;
	// }
	// free(pipe->envp->env);
	free(pipe->envp);
	free(pipe);
}