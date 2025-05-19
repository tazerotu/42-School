/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:13 by ttas              #+#    #+#             */
/*   Updated: 2025/05/19 10:41:52 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

// Verify if Variable given with command or not 
// (ex: "unset VAR1 ..." or only "unset")
// Works with multiple variables
static int	variable_amount(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

// Verify Exist
int	variable_pos(t_env *envp, char *str)
{
	int		pos;
	t_env	*tmp;

	pos = 1;
	tmp = envp;
	ft_printf("str : %s\n\n", str);
	while (tmp)
	{
		if (ft_strncmp(tmp->env, str, ft_strlen(str)) == 0)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}

static void	delete_variable(t_env *envp, int pos)
{
	t_env	*tmp;

	tmp = envp;
	if (pos != -1)
	{
		while (tmp && pos > 0)
		{
			tmp = tmp->next;
			pos--;
		}
		env_delone(tmp);
	}
}

// Parsing 	-> Variable == Found
// Variable -> env_delone
void	bi_unset(char **str, t_pipe *pipe)
{
	int		i;
	t_env	*tmp;

	if (variable_amount(str) <= 1)
	{
		pipe->exit_status = INVALID_CMD;
		return ;
	}
	i = 1;
	while (str[i])
	{
		tmp = pipe->envp;
		delete_variable(tmp, variable_pos(tmp->next, str[i]));
		i++;
	}
	pipe->exit_status = 0;
	return ;
}
