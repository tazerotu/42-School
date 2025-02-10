/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:13 by ttas              #+#    #+#             */
/*   Updated: 2025/02/10 20:56:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/Executor.h"

// Verify if Variable given with command or not (ex: "unset VAR1 ..." or only "unset")
// Works with multiple variables
static int variable_amount(char **str)
{
	int i;
	i = 0;
	while(str[i] != NULL)
		i++;
	return(i);
}

// Verify Exist
static bool variable_exist(t_env *envp, char *str)
{
	bool exist;
	exist = false;
	while(envp && envp->next != NULL)
	{
		if(ft_strncmp(envp->env, str, ft_strlen(str)) != 0)
			exist = true;
		envp = envp->next;
	}
	return (exist);
}

// Parsing 	-> Variable == Found
// Variable -> env_delone
void bi_unset(t_env *envp, char **str)
{
	int i;
	if(variable_amount(str) <= 1)
		return ;
	i = 1;
	while(str[i])
	{
		if(variable_exist(envp, str[i]) == true)
		{
			while(envp && ft_strncmp(envp->env, str[i], ft_strlen(str[i])) != 0)
				envp = envp->next;
			env_delone(envp);
		}
		i++;
	}
}