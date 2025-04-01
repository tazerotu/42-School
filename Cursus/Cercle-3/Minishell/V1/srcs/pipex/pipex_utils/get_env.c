/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:30:22 by ttas              #+#    #+#             */
/*   Updated: 2025/04/01 14:46:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

char	**get_env_char(t_env *envp)
{
	char	**env;
	int		i;
	int		j;

	i = env_size(envp);
	env = malloc((i + 1) * sizeof(char *));
	j = -1;
	while (envp)
	{
		env[++j] = malloc((ft_strlen(envp->env) + 1) * sizeof(char *));
		ft_printf("line %d : %s\n", j, envp->env);
		ft_strlcpy(env[j], envp->env, (ft_strlen(envp->env) + 1));
		envp = envp->next;
	}
	j++;
	env[j] = NULL;
	return (env);
}

char	*get_env(t_env *envp, char *str)
{
	char	*env;
	char 	*tmp;

	tmp = NULL;
	while (envp)
	{
		if (ft_strnstr(envp->env, str, ft_strlen(str)))
		{
			env = ft_strdup(envp->env);
			env = ft_strchr(env, '=');
			env++;
			tmp = env;
			return (tmp);
		}
		envp = envp->next;
	}
	return (NULL);
}
