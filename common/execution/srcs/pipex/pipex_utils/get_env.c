/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:30:22 by ttas              #+#    #+#             */
/*   Updated: 2025/05/19 17:34:37 by clai-ton         ###   ########.fr       */
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
		ft_strlcpy(env[j], envp->env, (ft_strlen(envp->env) + 1));
		envp = envp->next;
	}
	j++;
	env[j] = NULL;
	return (env);
}

char	*get_env(t_env *envp, char *str)
{
	int	i;
	int	env_name_len;
	int	max_len;

	i = ft_strlen(str);
	while (envp)
	{
		env_name_len = 0;
		while (envp->env[env_name_len] && envp->env[env_name_len] != '=')
			++env_name_len;
		if (i > env_name_len)
			max_len = i;
		else
			max_len = env_name_len;
		if (ft_strncmp(envp->env, str, max_len) == 0)
		{
			while (envp->env[i] && envp->env[i] != '=')
				++i;
			++i;
			return (ft_substr(envp->env, i, env_name_len - i));
		}
		envp = envp->next;
	}
	return (NULL);
}
