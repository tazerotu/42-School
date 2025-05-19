/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:07 by ttas              #+#    #+#             */
/*   Updated: 2025/05/19 14:04:05 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

// Get the current working directory
void	bi_pwd(t_pipe *pipe)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		pipe->exit_status = 127;
		error_message_exec(ERROR_PWD, NULL);
		return ;
	}
	ft_printf("%s\n", cwd);
	free(cwd);
	pipe->exit_status = 0;
	return ;
}

// ft_printf("%s\n", ft_strnstr(cwd, "Minishell", ft_strlen(cwd)));
