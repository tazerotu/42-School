/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:59:24 by marvin            #+#    #+#             */
/*   Updated: 2025/05/19 20:59:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/executor.h"

t_env	*find_env_pos(t_env *env, int pos)
{
	if (pos == -1)
	{
		ft_fprintf(2, "ERROR : %d\n", ERROR_ENV);
		return (NULL);
	}
	while (pos-- > 0)
		env = env->next;
	return (env);
}

int	free_pwd(char *pwd, char *str)
{
	if (pwd)
		free(pwd);
	error_message_exec(ERROR_DIR, str);
	return (127);
}

t_env	*find_env_var(t_env *env, char *name)
{
	t_env	*tmp;
	int		var_len;
	int		env_len;

	tmp = env;
	var_len = 0;
	while (name[var_len] && name[var_len] != '=')
		++var_len;
	while (tmp)
	{
		env_len = 0;
		while (tmp->env[env_len] && tmp->env[env_len] != '=')
			++env_len;
		if (env_len == var_len && !ft_strncmp(tmp->env, name, var_len))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
