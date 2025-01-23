/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Verify_built-in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:06:09 by ttas              #+#    #+#             */
/*   Updated: 2025/01/23 10:11:51 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/Executor.h"

void verify_builtin(void)
{
	char *str;
	
	if(ft_strnstr(str, "echo", 4))
		bi_echo(void);
	if(ft_strnstr(str, "cd", 2))
		bi_cd(void);
	if(ft_strnstr(str, "pwd", 3))
		bi_pwd(void);
	if(ft_strnstr(str, "export", 6))
		bi_export(void);
	if(ft_strnstr(str, "unset", 5))
		bi_unset(void);
	if(ft_strnstr(str, "env", 3))
		bi_env(void);
	if(ft_strnstr(str, "exit", 4))
		bi_exit(void);
}