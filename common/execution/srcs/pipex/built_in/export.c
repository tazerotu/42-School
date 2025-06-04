/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:04 by ttas              #+#    #+#             */
/*   Updated: 2025/06/04 09:43:26 by ttas             ###   ########.fr       */
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
		return (error_message_exec(ERROR_EXPORT, str));
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (error_message_exec(ERROR_EXPORT, str));
		i++;
	}
	if (ft_strlen(str) > 2097152)
		return (error_message_exec(ERROR_EXPORT, str));
	return (1);
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

static t_env	*modify_export(t_env *tmp, char *str)
{
	tmp = find_env_pos(tmp, variable_pos(tmp, str));
	if (tmp)
	{
		free(tmp->env);
		tmp->env = ft_strdup(str);
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
		return (bubble_sort(pipe->envp));
	tmp = pipe->envp;
	while (str[++i])
	{
		if (syntax(str[i]) < 0)
		{
			pipe->exit_status = 126;
			return (NULL);
		}
		tmp = verify_exist(tmp, str[i]);
		if (!tmp)
			env_add_back(pipe->envp, env_new(str[i]));
		else
		{
			modify_export(tmp, str[i]);
		}
	}
	pipe->exit_status = 0;
	return (tmp);
}
// for (int j = 0; str[j]; j++)
// // printf("str[%d] = '%c' (%d)\n", j, str[i][j], (unsigned char)str[i][j]);
// printf("export : %s\n", str[i]);
// printf("syntax : %d\n\n", syntax(str[i]));