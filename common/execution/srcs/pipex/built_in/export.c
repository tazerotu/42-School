/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:04 by ttas              #+#    #+#             */
/*   Updated: 2025/05/19 13:11:15 by clai-ton         ###   ########.fr       */
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
		if (verify_exist(tmp, str[i]) == NULL)
			env_add_back(tmp, env_new(str[i]));
		else
		{
			tmp = find_env_pos(tmp, variable_pos(tmp, str[i]));
			ft_printf("tmp, str : %s, %s, %d\n\n", tmp->env, str[i], i);
			if (tmp)
				ft_strlcpy(tmp->env, str[i], ft_strlen(str[i])+1);
		}
	}
	pipe->exit_status = 0;
	return (tmp);
}
