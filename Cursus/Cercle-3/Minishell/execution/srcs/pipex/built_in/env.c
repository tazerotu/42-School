/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:04:54 by ttas              #+#    #+#             */
/*   Updated: 2025/05/06 16:37:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

void	bi_env(t_env *envp, t_pipe *pipe)
{
	t_env	*tmp;

	if (pipe->cmd->cmd[1] != NULL)
	{
		error_message(ERROR_ENV, NULL);
		return ;
	}
	tmp = envp;
	while (tmp && tmp->next)
	{
		ft_printf("%s\n", tmp->env);
		tmp = tmp->next;
	}
	ft_printf("%s\n", tmp->env);
	pipe->exit_status = 0;
	return ;
}
