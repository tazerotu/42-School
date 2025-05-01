/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_built_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:06:09 by ttas              #+#    #+#             */
/*   Updated: 2025/04/30 18:33:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

void	verify_builtin(t_pipe *pipe)
{
	char	*str;

	str = pipe->cmd->cmd[0];
	if (!ft_strncmp(str, "echo", 4) || !ft_strncmp(str, "cd", 2) || 
		!ft_strncmp(str, "pwd", 3) || !ft_strncmp(str, "export", 6) || 
		!ft_strncmp(str, "unset", 5) || !ft_strncmp(str, "env", 3) || 
		!ft_strncmp(str, "exit", 4))
	{
		launch_builtin(pipe);
	}
}

void	launch_builtin(t_pipe *pipe)
{
	char	*str;

	str = pipe->cmd->cmd[0];
	if (ft_strncmp(str, "echo", 4))
		bi_echo(pipe->cmd->cmd, pipe);
	if (ft_strncmp(str, "cd", 2))
		bi_cd(pipe->envp, pipe->cmd->cmd, pipe);
	if (ft_strncmp(str, "pwd", 3))
		bi_pwd(pipe);
	if (ft_strncmp(str, "export", 6))
		bi_export(pipe, pipe->envp, pipe->cmd->cmd);
	if (ft_strncmp(str, "unset", 5))
		bi_unset(pipe->envp, pipe->cmd->cmd, pipe);
	if (ft_strncmp(str, "env", 3))
		bi_env(pipe->envp, pipe);
	if (ft_strncmp(str, "exit", 4))
		bi_exit(pipe, pipe->cmd->cmd);
	return ;
}
