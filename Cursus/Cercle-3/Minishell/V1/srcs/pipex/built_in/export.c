/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:04 by ttas              #+#    #+#             */
/*   Updated: 2025/03/11 10:44:05 by ttas             ###   ########.fr       */
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
static bool	syntax(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]) && str[i] != '_')
		return (0);
	while (str[i] || str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	if (!str[i])
		return (0);
	else
	{
		i++;
		if (str[i] == ' ')
			return (0);
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
t_env	*bi_export(t_env *env, char **str)
{
	int		i;
	t_env	*tmp;

	i = 1;
	tmp = env;
	if (!str[1])
		return (NULL);
	while (str[i])
	{
		if (syntax(str[i]))
			return (NULL);
		if (verify_exist(tmp, str[i]) == NULL)
			env_add_back(tmp, env_new(str[i]));
		else
		{
			tmp = find_env_pos(tmp, variable_pos(tmp, str[i]));
			ft_strlcpy(tmp->env, str[i], ft_strlen(str[i]));
		}
		i++;
	}
	return (tmp);
}
