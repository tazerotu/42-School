/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:01 by ttas              #+#    #+#             */
/*   Updated: 2025/05/05 09:28:47 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

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
	exit = atoi(cmd[1]);
	while (exit > 255)
		exit -= 256;
	pipe->exit = exit;
	return (exit);
}
