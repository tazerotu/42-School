/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:04 by ttas              #+#    #+#             */
/*   Updated: 2025/05/19 20:13:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

// Verify syntax
// Syntax :	
//	Starts with either isalpha or '_'
// 	Can't contain '-'
//	Can't contain spaces
//	Has to have a '=' between VARIABLE_NAME and value ex: VARIABLE_NAME=value
//	If value contains spaces, only take value until first space
//	if value contains spaces but is encapslutated by "" or '' take entire string
static int	syntax(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]) && str[i] != '_')
		return (-1);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (-2);
		i++;
	}
	if (!str[i])
		return (-3);
	else
	{
		i++;
		if (str[i] == ' ')
			return (-4);
		return (1);
	}
}

// Verify if it exist
static t_env	*verify_exist(t_env *env, char *str)
{
	t_env	*tmp;
	int		pos;

	tmp = env;
	pos = variable_pos(tmp, str);
	if (pos == -1)
		return (NULL);
	else
	{
		while (pos > 0)
		{
			tmp = tmp->next;
			pos--;
		}
	}
	return (tmp);
}

// Add Variable -> env_addback if not existing
// Modify Variable if already existing
// If export VARIABLE_NAME1=$VARIABLE_NAME2 -> 
// find variable in env and set VARIABLE_NAME2 value to VARIABLE_NAME1
// Multiple variables possible
t_env	*bi_export(t_pipe *pipe, char **str)
{
	int		i;
	t_env	*tmp;
	int		pos;

	i = 0;
	if (!str[1])
		return (NULL);
	tmp = pipe->envp;
	while (str[++i])
	{
		if (syntax(str[i]) < 0)
		{
			pipe->exit_status = INVALID_CMD;
			return (NULL);
		}
		tmp = verify_exist(tmp, str[i]);
		if (!tmp)
			env_add_back(pipe->envp, env_new(str[i]));
		else
		{
			pos = variable_pos(tmp, str[i]);
			tmp = find_env_pos(tmp, pos);
			if (tmp)
			{
				free(tmp->env);
				tmp->env = ft_strdup(str[i]);
			}
		}
	}
	pipe->exit_status = 0;
	return (tmp);
}
