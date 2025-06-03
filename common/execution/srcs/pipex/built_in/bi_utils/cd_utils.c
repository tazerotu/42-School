/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:32:04 by marvin            #+#    #+#             */
/*   Updated: 2025/06/03 16:32:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/executor.h"

static char	*get_old_pwd(t_env *env)
{
	char		*old_pwd;
	t_env		*pwd_node;

	old_pwd = getcwd(NULL, 0);
	if (old_pwd)
		return (old_pwd);
	pwd_node = find_env_var(env, "PWD");
	if (pwd_node)
		return (ft_strdup(pwd_node->env + 4));
	return (ft_strdup("UNKNOWN"));
}

static void	update_pwd_logical(t_env *env)
{
	t_env	*pwd_node;
	char	*logical;

	pwd_node = find_env_var(env, "PWD");
	if (!pwd_node)
		return ;
	logical = ft_strjoin(pwd_node->env + 4, "/..");
	if (!logical)
		return ;
	change_pwd(env, "PWD=", logical);
	free(logical);
}
int	previous_cd(t_env *env)
{
	char	*old_pwd;
	char	*new_pwd;

	old_pwd = get_old_pwd(env);
	if (chdir("..") == -1)
	{
		ft_fprintf(2, "cd: error accessing parent directory\n");
		free(old_pwd);
		return (1);
	}
	change_pwd(env, "OLDPWD=", old_pwd);
	free(old_pwd);
	new_pwd = getcwd(NULL, 0);
	if (new_pwd)
	{
		change_pwd(env, "PWD=", new_pwd);
		free(new_pwd);
	}
	else
		update_pwd_logical(env);
	return (0);
}
