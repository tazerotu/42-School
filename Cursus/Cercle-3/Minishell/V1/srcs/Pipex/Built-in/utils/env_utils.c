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

void env_add_back(t_env **envp, t_env *new)
{
	if (!envp || !new)
		return ;
	if (envp)
	{
		new->previous = *envp;
		env_last(*envp)->next = new;
	}
	else
		*envp = new;
}

void env_delone(t_env *envp)
{
	if (!envp)
		return ;
	if (envp->previous)
		envp->previous->next = envp->next;
	if (envp->next)	
		envp->next->previous = envp->previous;
	// free(envp->env);
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
