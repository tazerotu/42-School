/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:04:54 by ttas              #+#    #+#             */
/*   Updated: 2025/05/05 09:24:33 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

void	bi_env(t_env *envp, t_pipe *pipe)
{
	t_env	*tmp;

	if (pipe->cmd->cmd[1] != NULL)
		return (error_message(ERROR_ENV));
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
