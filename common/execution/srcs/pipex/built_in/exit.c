/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:01 by ttas              #+#    #+#             */
/*   Updated: 2025/05/26 14:04:31 by clai-ton         ###   ########.fr       */
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
			ft_printf("Non numerical argument\n");
			return (INVALID_CMD);
		}
	}
	return (1);
}

int	bi_exit(t_pipe *pipe, char **cmd)
{
	int	i;
	int	exit_nbr;

	i = 0;
	while (cmd[i])
		i++;
	if (i > 2)
	{
		ft_printf("Too many arguments\n");
		return (pipe->exit = INVALID_CMD);
	}
	i = 0;
	if (cmd[1])
	{
		if (syntax(cmd[1]) != 1)
			return (pipe->exit = INVALID_CMD);
		exit_nbr = exit_args(cmd);
	}
	else
		exit_nbr = 1;
	pipe->exit = exit_nbr;
	exit(pipe->exit);
}
