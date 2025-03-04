/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:04:58 by ttas              #+#    #+#             */
/*   Updated: 2025/03/04 10:26:28 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/Executor.h"

static void change_oldpwd(t_env *env, char **str)
{
	
	return ;
}

static void change_dir(t_env *env, char **str, bool home)
{
	
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
	{
		change_dir(env, str, true);
		return ;
	}
	else
	{
		change_dir(env, str, false);
		return ;
	}
}