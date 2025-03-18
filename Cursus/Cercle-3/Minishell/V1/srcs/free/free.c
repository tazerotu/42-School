/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:23:16 by ttas              #+#    #+#             */
/*   Updated: 2025/03/18 09:16:02 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

void free_all(t_pipe *pipe)
{
	t_env *tmp;
	while(pipe->envp->previous)
		pipe->envp = pipe->envp->previous;	 
	while(pipe->envp)
	{
		tmp = pipe->envp->next;
		free(pipe->envp);
		pipe->envp = tmp;
	}
	free(pipe->envp);
	free(pipe);
}
