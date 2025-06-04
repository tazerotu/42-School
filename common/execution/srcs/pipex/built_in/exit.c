/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:01 by ttas              #+#    #+#             */
/*   Updated: 2025/06/04 10:11:12 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_overflow(char *str)
{
	long long	nb;

	if (!is_number(str))
		return (1);
	nb = ft_atol(str);
	if (nb > LLONG_MAX || nb < LLONG_MIN)
		return (1);
	return (0);
}

static void	exit_error(char *arg)
{
	ft_fprintf(2, "exit: %s: numeric argument required\n", arg);
	exit(2);
}

static int	get_exit_code(char **cmd, t_pipe *pipe)
{
	long long	code;
	int			argc;

	argc = 0;
	while (cmd[argc])
		argc++;
	if (argc >= 2)
	{
		if (!is_number(cmd[1]) || is_overflow(cmd[1]))
			exit_error(cmd[1]);
		if (argc > 2)
		{
			ft_fprintf(2, "exit: too many arguments\n");
			pipe->exit_status = 1;
			return (-1);
		}
		code = ft_atol(cmd[1]) % 256;
		if (code < 0)
			code += 256;
		return ((int)code);
	}
	return (pipe->exit_status);
}

int	bi_exit(t_pipe *pipe, char **cmd)
{
	int	exit_code;

	ft_putstr_fd("exit\n", STDERR_FILENO);
	exit_code = get_exit_code(cmd, pipe);
	if (exit_code == -1)
		return (1);
	exit(exit_code);
}
