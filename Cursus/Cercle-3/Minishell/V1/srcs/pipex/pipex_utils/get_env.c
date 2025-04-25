/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:30:22 by ttas              #+#    #+#             */
/*   Updated: 2025/04/25 11:14:20 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

// ft_printf("line %d : %s\n", j, envp->env);
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
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (str[i])
		i++;
	if (str[--i] != '\0')
		str[i] = '\0';
	while (envp)
	{
		if (ft_strnstr(envp->env, str, ft_strlen(str)))
		{
			env = ft_strdup(envp->env);
			while (env[i] && env[i] != '=')
				i++;
			i++;
			tmp = ft_substr(env, i, ft_strlen(env) - i);
			free(env);
			return (tmp);
		}
		envp = envp->next;
	}
	return (NULL);
}
