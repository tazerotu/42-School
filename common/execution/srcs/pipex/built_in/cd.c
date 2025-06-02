/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:04:58 by ttas              #+#    #+#             */
/*   Updated: 2025/06/02 11:12:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

static char	*get_pwd(char *pwd)
{
	free(pwd);
	pwd = getcwd(NULL, 0);
	return (pwd);
}

static void	change_pwd(t_env *env, char *path, char *cwd)
{
	char	*new_str;
	t_env	*tmp;

	new_str = NULL;
	tmp = env;
	while (tmp->previous)
		tmp = tmp->previous;
	if (!cwd)
	{
		ft_fprintf(1, "ERROR : %d\n", ERROR_PWD);
		return ;
	}
	tmp = find_env_pos(tmp, variable_pos(tmp->next, path) + 1);
	new_str = path;
	new_str = ft_strjoin(new_str, cwd);
	if (tmp->env)
	{
		free(tmp->env);
		tmp->env = ft_strdup(new_str);
	}
	free(new_str);
	return ;
}

static int	change_dir(t_env *env, char *str, bool home)
{
	t_env	*tmp;
	char	*pwd;

	tmp = env;
	pwd = getcwd(NULL, 0);
	if (home == true)
	{
		tmp = find_env_pos(tmp, variable_pos(tmp, "HOME"));
		if (chdir(tmp->env + 5))
			return (free_pwd(pwd, str));
		change_pwd(tmp, "OLDPWD=", pwd);
		pwd = get_pwd(pwd);
		change_pwd(tmp, "PWD=", pwd);
	}
	else
	{
		if (chdir(str))
			return (free_pwd(pwd, str));
		change_pwd(tmp, "OLDPWD=", pwd);
		pwd = get_pwd(pwd);
		change_pwd(tmp, "PWD=", pwd);
	}
	free(pwd);
	return (0);
}

void	bi_cd(t_env *env, char **path, t_pipe *pipe)
{
	int	i;
	int	err;

	err = 0;
	i = 0;
	while (path[i])
		i++;
	if (i > 2)
	{
		ft_fprintf(2, "ERROR : %d", ERROR_DIR);
		pipe->exit_status = 127;
		return ;
	}
	if (i == 1)
		err = change_dir(env, path[0], true);
	else
		err = change_dir(env, path[1], false);
	if (err == 0)
		pipe->exit_status = 0;
	else
		pipe->exit_status = 127;
	return ;
}
