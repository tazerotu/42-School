/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:13 by ttas              #+#    #+#             */
/*   Updated: 2025/02/27 15:22:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/Executor.h"

// Verify if Variable given with command or not (ex: "unset VAR1 ..." or only "unset")
// Works with multiple variables
static int variable_amount(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

// Verify Exist
static int variable_pos(t_env *envp, char *str)
{
	int pos;
	pos = 1;
	t_env *tmp;
	tmp = envp;
	while(tmp && tmp->next != NULL)
	{
		if(ft_strncmp(tmp->env, str, ft_strlen(str)) == 0)
			return(pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}

void delete_variable(t_env *envp, int pos)
{
	t_env *tmp;
	tmp = envp;
	if(pos != -1)
	{
		while(tmp && tmp->next && pos > 0)
		{
			tmp = tmp->next;
			pos--;
		}
		env_delone(tmp);
	}
}

// Parsing 	-> Variable == Found
// Variable -> env_delone
void bi_unset(t_env *envp, char **str)
{
	int i;
	t_env *tmp;
	tmp = envp;
	if(variable_amount(str) <= 1)
		return ;
	i = 1;
	printf("\n");
	while(str[i])
	{
		delete_variable(tmp, variable_pos(tmp->next, str[i]));
		i++;
	}

}