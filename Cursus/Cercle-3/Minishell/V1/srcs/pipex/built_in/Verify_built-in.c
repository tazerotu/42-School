/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Verify_built-in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:06:09 by ttas              #+#    #+#             */
/*   Updated: 2025/03/06 09:39:22 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

void verify_builtin(t_pipe *pipe)
{
	char *str;
	str = pipe->cmd->cmd[0]	
	if(ft_strnstr(str, "echo", 4))
		bi_echo(pipe);
	if(ft_strnstr(str, "cd", 2))
		bi_cd(void);
	if(ft_strnstr(str, "pwd", 3))
		bi_pwd(void);
	if(ft_strnstr(str, "export", 6))
		bi_export(void);
	if(ft_strnstr(str, "unset", 5))
		bi_unset(void);
	if(ft_strnstr(str, "env", 3))
		bi_env(void);
	if(ft_strnstr(str, "exit", 4))
		bi_exit(void);
}