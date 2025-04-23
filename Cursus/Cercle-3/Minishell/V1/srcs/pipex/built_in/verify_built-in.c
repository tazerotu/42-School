/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_built-in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:06:09 by ttas              #+#    #+#             */
/*   Updated: 2025/04/23 12:34:15 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

void	verify_builtin(t_pipe *pipe)
{
	char	*str;

	str = pipe->cmd->cmd[0];
	if (ft_strncmp(str, "echo", 4))
		return (0);
	if (ft_strncmp(str, "cd", 2))
		return (0);
	if (ft_strncmp(str, "pwd", 3))
		return (0);
	if (ft_strncmp(str, "export", 6))
		return (0);
	if (ft_strncmp(str, "unset", 5))
		return (0);
	if (ft_strncmp(str, "env", 3))
		return (0);
	if (ft_strncmp(str, "exit", 4))
		return (0);
	return (-1);
}

void	launch_builtin(t_pipe *pipe)
{
	char	*str;

	str = pipe->cmd->cmd[0];
	if (ft_strncmp(str, "echo", 4))
		bi_echo(pipe);
	if (ft_strncmp(str, "cd", 2))
		bi_cd(void);
	if (ft_strncmp(str, "pwd", 3))
		bi_pwd(void);
	if (ft_strncmp(str, "export", 6))
		bi_export(void);
	if (ft_strncmp(str, "unset", 5))
		bi_unset(void);
	if (ft_strncmp(str, "env", 3))
		bi_env(void);
	if (ft_strncmp(str, "exit", 4))
		bi_exit(void);
	return (0);
}
