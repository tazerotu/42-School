/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:04:54 by ttas              #+#    #+#             */
/*   Updated: 2025/05/16 11:41:14 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

void	bi_env(t_env *envp, t_pipe *pipe)
{
	t_env	*tmp;

	if (pipe->cmd->arg_tok[1] != NULL)
	{
		error_message_exec(ERROR_ENV, NULL);
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
