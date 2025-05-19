/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:01 by ttas              #+#    #+#             */
/*   Updated: 2025/05/19 18:59:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

static int	exit_args(char **cmd)
{
	int	exit;

	exit = ft_atoi(cmd[1]);
	while (exit > 255)
		exit -= 256;
	return (exit);
}

static int	syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i++]) == 0)
		{
			ft_printf("Non numerical argument");
			return (INVALID_CMD);
		}
	}
	return (1);
}

int	bi_exit(t_pipe *pipe, char **cmd)
{
	int	i;
	int	exit;

	i = 0;
	while (cmd[i])
		i++;
	if (i > 2)
	{
		ft_printf("Too many arguments");
		return (pipe->exit = INVALID_CMD);
	}
	i = 0;
	if (cmd[1])
	{
		if (syntax(cmd[1]) != 1)
			return (pipe->exit = INVALID_CMD);
		exit = exit_args(cmd);
	}
	else
		exit = 1;
	pipe->exit = exit;
	return (exit);
}
