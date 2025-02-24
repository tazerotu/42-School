/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:23:16 by ttas              #+#    #+#             */
/*   Updated: 2025/02/24 16:05:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/Executor.h"

void free_all(t_pipe *pipe)
{
	t_cmd *tmp;
	t_cmd *tmp2;

	tmp = pipe->cmd;
	while(tmp)
	{
		tmp2 = tmp->next;
		free(tmp->cmd);
		free(tmp->redir);
		free(tmp);
		tmp = tmp2;
	}
	free(pipe->envp);
	free(pipe);
}