/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_built_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:06:09 by ttas              #+#    #+#             */
/*   Updated: 2025/06/04 09:28:14 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

int	verify_builtin1(t_pipe *pipe)
{
	char	*str;

	str = pipe->cmd->arg_tok[0];
	if (pipe->cmd->arg_tok[0] == NULL)
		return (0);
	if (ft_strncmp(str, "echo", INT_MAX) == 0
		|| ft_strncmp(str, "cd", INT_MAX) == 0
		|| ft_strncmp(str, "pwd", INT_MAX) == 0
		|| ft_strncmp(str, "export", INT_MAX) == 0
		|| ft_strncmp(str, "unset", INT_MAX) == 0
		|| ft_strncmp(str, "env", INT_MAX) == 0
		|| ft_strncmp(str, "exit", INT_MAX) == 0)
		return (1);
	else
		return (0);
}

int	verify_builtin2(t_cmd *cmd)
{
	char	*str;

	str = cmd->arg_tok[0];
	if (cmd->arg_tok[0] == NULL)
		return (0);
	if (ft_strncmp(str, "exit", INT_MAX) == 0
		|| ft_strncmp(str, "cd", INT_MAX) == 0
		|| ft_strncmp(str, "export", INT_MAX) == 0
		|| ft_strncmp(str, "unset", INT_MAX) == 0)
		return (1);
	else
		return (0);
}

void	launch_builtin(t_pipe *pipe)
{
	char	*str;

	str = pipe->cmd->arg_tok[0];
	if (is_exit_command(pipe->cmd) && (pipe->cmd->next || pipe->prev_fd != -1))
	{
		return ;
	}
	if (ft_strncmp(str, "echo", INT_MAX) == 0)
		bi_echo(pipe->cmd->arg_tok, pipe);
	else if (ft_strncmp(str, "cd", INT_MAX) == 0)
		bi_cd(pipe->envp, pipe->cmd->arg_tok, pipe);
	else if (ft_strncmp(str, "pwd", INT_MAX) == 0)
		bi_pwd(pipe);
	else if (ft_strncmp(str, "export", INT_MAX) == 0)
		bi_export(pipe, pipe->cmd->arg_tok);
	else if (ft_strncmp(str, "unset", INT_MAX) == 0)
		bi_unset(pipe->cmd->arg_tok, pipe);
	else if (ft_strncmp(str, "env", INT_MAX) == 0)
		bi_env(pipe->envp, pipe);
	else if (ft_strncmp(str, "exit", INT_MAX) == 0)
		bi_exit(pipe, pipe->cmd->arg_tok);
	return ;
}
