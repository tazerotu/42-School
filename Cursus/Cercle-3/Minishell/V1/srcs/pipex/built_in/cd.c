/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:04:58 by ttas              #+#    #+#             */
/*   Updated: 2025/03/06 11:03:33 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

static t_env	*find_env_pos(t_env *env, int pos)
{
	if (pos == -1)
	{
		ft_fprintf(1, "ERROR : %d\n", ERROR_ENV);
		return (NULL);
	}
	while (pos-- > 0)
		env = env->next;
	return (env);
}

static char	*expand_pwd(t_env *envp, char *str)
{
	t_env	*tmp;
	char	*new_str;
	char	*env;

	tmp = envp;
	if (str[0] == '~')
	{
		// int pos = variable_pos(tmp, "HOME");
		// while(pos > 0)
		// {
		// 	printf("%s\t\t%d\n", tmp->env, pos);
		// 	pos--;
		// 	tmp = tmp->next;
		// }
		tmp = find_env_pos(tmp->next, variable_pos(tmp->next, "HOME"));
		printf("\n%s\n", tmp->env);
		env = ft_strnstr(tmp->env , "=", 5);
		new_str = ft_strjoin(new_str, env);
	}
	new_str = ft_strjoin(new_str, str);
	return (new_str);
}

static void	change_pwd(t_env *env, char *path)
{
	char	*cwd;
	t_env	*tmp;

	tmp = env;
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		ft_fprintf(1, "ERROR : %d\n", ERROR_PWD);
		return ;
	}
	tmp = find_env_pos(tmp, variable_pos(tmp, path));
	// tmp->env = cwd;
	free(cwd);
	return ;
}

static void	change_dir(t_env *env, char *str, bool home)
{
	t_env	*tmp;
	char	*new_str;

	tmp = env;
	change_pwd(tmp, "OLDPWD");
	if (home == true)
	{
		tmp = find_env_pos(tmp, variable_pos(tmp, "HOME"));
		if (!chdir(tmp->env))
		{
			ft_fprintf(1, "cd: no such file or directory: %s", tmp->env);
			return ;
		}
		else
			change_pwd(tmp, "PWD");
	}
	else
	{
		new_str = expand_pwd(env, str);
		printf("%s\n", new_str);
		if (!chdir(new_str))
			ft_fprintf(1, "cd: no such file or directory: %s", new_str);
		else
			change_pwd(tmp, "PWD");
	}
	return ;
}

void	bi_cd(t_env *env, char **path)
{
	int	i;

	i = 0;
	while(path[i])
		i++;
	if (i > 2)
	{
		ft_fprintf(1, "ERROR : %d", ERROR_DIR);
		return ;
	}
	if (i == 1)
		change_dir(env, path[0], true);
	else
		change_dir(env, path[1], false);
}
