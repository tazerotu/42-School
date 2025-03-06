/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:04 by ttas              #+#    #+#             */
/*   Updated: 2025/03/06 09:39:11 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

// Verify syntax
// Syntax :		Starts with either isalpha or '_'
// 				Can't contain '-'
//				Can't contain spaces
//				Has to have a '=' between VARIABLE_NAME and value ex: VARIABLE_NAME=value
//				If value contains spaces, only take value until first space
//				if value contains spaces but is encapslutated by "" or '' take entire string
static bool syntax(char *str)
{
	int i;
	i = 0;
	if(!ft_isalpha(str[i]) || !str[i] == '_')
		return(0);
	while(str[i] || str[i] != '=')
	{
		if(!ft_isalnum(str[i]) || !str[i] == '_')
			return(0);
		i++;
	}
	if(!str[i])
		return(0);
	else
	{
		i++;
		if(str[i] == ' ')
			return(0);
		return(1);
	}
}

// Verify if it exist
static t_env *verify_exist(t_pipe *pipe, char *str)
{

} 

// Add Variable -> env_addback if not existing
// Modify Variable if already existing
// If export VARIABLE_NAME1=$VARIABLE_NAME2 -> find variable in env and set VARIABLE_NAME2 value to VARIABLE_NAME1
// Multiple variables possible
void bi_export(t_pipe *pipe, char *str)
{
	if(!syntax(str))
		return ;
	if(verify_exist(pipe, str) == NULL)
		env_add_back(env_last(pipe->envp), env_new(str));
	else
	{
		pipe->envp = verify_exist(pipe, str);
		ft_strlcpy(pipe->envp->str, str, ft_strlen(str));
	}	
}