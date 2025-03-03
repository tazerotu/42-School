/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:20:48 by marvin            #+#    #+#             */
/*   Updated: 2025/01/30 17:20:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../Includes/Executor.h"

void env_add_back(t_env *envp, t_env *new)
{
	if (!envp || !new)
		return ;
	if (envp)
	{
		new->previous = env_last(envp);
		env_last(envp)->next = new;
	}
	else
		envp = new;
}

void env_delone(t_env *envp)
{
	t_env *tmp;
	tmp = envp;
	if (!tmp)
		return ;
	if (tmp->previous)
		tmp->previous->next = tmp->next;
	if (tmp->next)	
		tmp->next->previous = tmp->previous;
	free(tmp);
}

void	*env_new(char *content)
{
	t_env	*env1;

	env1 = malloc(sizeof(t_env));
	if (!env1)
		return (NULL);
	env1->env = content;
	env1->next = NULL;
	env1->previous = NULL;
	return (env1);
}

t_env *env_last(t_env *env)
{
	while (env && env->next)
	{
		env = env->next;
	}
	return (env);
}

int env_size(t_env *env)
{
	int	size;

	size = 0;
	while (env)
	{
		size++;
		env = env->next;
	}
	return (size);
}
