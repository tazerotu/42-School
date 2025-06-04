/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:07 by ttas              #+#    #+#             */
/*   Updated: 2025/06/02 15:48:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

// Get the current working directory
void	bi_pwd(t_pipe *pipe)
{
	t_env	*tmp;

	tmp = find_env_pos(pipe->envp, variable_pos(pipe->envp, "PWD"));
	if (!tmp || !tmp->env)
	{
		error_message_exec(ERROR_PWD, NULL);
		pipe->exit_status = 1;
		return ;
	}
	ft_printf("%s\n", tmp->env + 4);
	pipe->exit_status = 0;
	return ;
}

// ft_printf("%s\n", ft_strnstr(cwd, "Minishell", ft_strlen(cwd)));
