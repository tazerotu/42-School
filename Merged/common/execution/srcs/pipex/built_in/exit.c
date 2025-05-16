/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:01 by ttas              #+#    #+#             */
/*   Updated: 2025/05/16 12:34:45 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

static int exit_args(char **cmd)
{
	int exit;
	
	if(cmd[1])
		exit = atoi(cmd[1]);
	else
		return (1);
	while(exit > 255)
		exit -= 256;
	return (exit);
}

int	bi_exit(t_pipe *pipe, char **cmd)
{
	int	i;
	int	exit;

	i = 0;
	while (cmd[i])
		i++;
	if (i > 2)
		ft_printf("Too many arguments");
	i = 0;
	while (cmd[1][i])
	{
		if (ft_isdigit(cmd[1][i++]) == 0)
		{
			ft_printf("Non numerical argument");
			pipe->exit = INVALID_CMD;
			return (INVALID_CMD);
		}
	}
	exit = exit_args(cmd);
	pipe->exit = exit;
	return (exit);
}
