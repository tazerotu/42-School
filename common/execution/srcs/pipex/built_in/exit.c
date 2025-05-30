/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:01 by ttas              #+#    #+#             */
/*   Updated: 2025/05/30 14:44:30 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

static int	exit_len(char *cmd)
{
	size_t	len;

	len = ft_strlen(cmd);
	if (len >= 12
		|| (len == 11
			&& ((cmd[0] != '-' && cmd[0] != '+')
				|| (cmd[0] == '+'
					&& ft_strncmp(cmd, "+9223372036854775807", 11) > 0)
				|| (cmd[0] == '-'
					&& ft_strncmp(cmd, "-9223372036854775808", 11) > 0)))
		|| (len == 10 && ft_strncmp(cmd, "9223372036854775807", 10) > 0))
		return (1);
	else
		return (0);
}

static int	exit_error(t_pipe *pipe, char **cmd)
{
	int	j;

	j = -1;
	while (cmd[1][++j])
		if (!ft_isdigit(cmd[1][j]))
			return (pipe->exit_status = 2);
	if (i > 2)
	{
		ft_printf("too many arguments\n");
		return (pipe->exit_status = 1);
	}
	if (exit_len(cmd[1]) == 1)
		return (pipe->exit_status = 2);
	return (pipe->exit_status = 127);
}

static int	exit_args(char **cmd)
{
	int	exit;

	if(exit_len(cmd[1]) == 1)
		ft_printf("exit : %s: numeric argument required\n", cmd[1]);
	exit = ft_atol(cmd[1]);
	exit %= 256;
	if (exit < 0)
		exit += 256;
	return (exit);
}

static int	syntax(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		++i;
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
