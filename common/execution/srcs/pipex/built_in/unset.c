/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:13 by ttas              #+#    #+#             */
/*   Updated: 2025/06/02 15:46:30 by marvin           ###   ########.fr       */
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
	t_pos	env_pos;

	pos = 1;
	tmp = envp;
	env_pos.var_len = 0;
	while (str[env_pos.var_len] && str[env_pos.var_len] != '=')
		++env_pos.var_len;
	while (tmp)
	{
		env_pos.env_name_len = 0;
		while (tmp->env[env_pos.env_name_len]
			&& tmp->env[env_pos.env_name_len] != '=')
			++env_pos.env_name_len;
		if (env_pos.var_len < env_pos.env_name_len)
			env_pos.max_len = env_pos.env_name_len;
		else
			env_pos.max_len = env_pos.var_len;
		if (!ft_strncmp(tmp->env, str, env_pos.max_len))
			return (pos - 1);
		++pos;
		tmp = tmp->next;
	}
	return (-1);
}

static void	delete_variable(t_env *envp, char *var_name)
{
	t_env	*tmp;
	int		env_name_len;
	int		max_len;
	int		var_len;

	tmp = envp;
	var_len = ft_strlen(var_name);
	while (tmp)
	{
		env_name_len = 0;
		while (tmp->env[env_name_len] && tmp->env[env_name_len] != '=')
			++env_name_len;
		if (var_len < env_name_len)
			max_len = env_name_len;
		else
			max_len = var_len;
		if (!ft_strncmp(tmp->env, var_name, max_len))
		{
			env_delone(tmp);
			return ;
		}
		tmp = tmp->next;
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
		delete_variable(tmp, str[i]);
		i++;
	}
	pipe->exit_status = 0;
	return ;
}
