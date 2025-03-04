/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:04:58 by ttas              #+#    #+#             */
/*   Updated: 2025/03/04 11:17:53 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/Executor.h"

static t_env *find_env_pos(t_env *env, int pos)
{
	if(pos == -1)
	{
		ft_fprintf(1, "ERROR : %d", ERROR_ENV);
		return (NULL);
	}
	while(pos-- > 0)
		env = env->next;
	return (env);
}

static void change_pwd(t_env *env, char *path)
{
	char *cwd;
    t_env *tmp;

	tmp = env;
    cwd = getcwd(NULL, 0);
    if(!cwd)
    {
        ft_fprintf(1, "ERROR : %d", ERROR_PWD);
        return ;
    }
	tmp = find_env_pos(tmp, variable_pos(tmp, path));
	tmp->env = cwd;
	free(cwd);
	return ;
}

static char *expand_pwd(t_env *env, char *str)
{
	char *new_str;
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == '~')
		{
			
		}
	}
	return(new_str);
}

static void change_dir(t_env *env, char **str, bool home)
{
	t_env *tmp;
	char *new_str;
	
	tmp = env;
	change_pwd(tmp, "OLDPWD");
	if(home == true)
	{
		if(!chdir(find_env_pos(tmp, variable_pos(tmp, "HOME"))))
			{
				ft_fprintf(1, "cd: no such file or directory: %s", tmp->env);
				return ;
			}
	}
	new_str = expand_pwd(env, str[1]);
	if(!chdir(new_str))
		ft_fprintf(1, "cd: no such file or directory: %s", new_str);
	else
		change_pwd(tmp, "PWD");
	return ;
}

void bi_cd(t_env *env, char **str)
{
	if(amount_arg(str) > 2)
	{
		ft_fprintf(1, "ERROR : %d", ERROR_DIR);
		return ;
	}
	if(amount_arg(str) == 1)
		change_dir(env, str, true);
	else
		change_dir(env, str, false);
}