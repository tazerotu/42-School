/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:13 by ttas              #+#    #+#             */
/*   Updated: 2025/05/23 11:02:03 by ttas             ###   ########.fr       */
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
	int		env_name_len;
	int		max_len;
	int		var_len;

	pos = 1;
	tmp = envp;
	var_len = 0;
	while (str[var_len] && str[var_len] != '=')
			++var_len;
	while (tmp)
	{
		env_name_len = 0;
		while (tmp->env[env_name_len] && tmp->env[env_name_len] != '=')
			++env_name_len;
		if (var_len < env_name_len)
			max_len = env_name_len;
		else
			max_len = var_len;
		if (!ft_strncmp(tmp->env, str, max_len))
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
