/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:07 by ttas              #+#    #+#             */
/*   Updated: 2025/03/04 11:13:58 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/Executor.h"

// Get the current working directory
// Find the "Minishell" substring in cwd
// No need to free str here since you're returning ret, and you won't use `str` anymore
void bi_pwd(void)
{
    char *cwd;
    
    cwd = getcwd(NULL, 0);
    if(!cwd)
    {
        ft_fprintf(1, "ERROR : %d", ERROR_PWD);
        return ;
    }
    ft_printf("%s\n", cwd);
	free(cwd);
}

    // ft_printf("%s\n", ft_strnstr(cwd, "Minishell", ft_strlen(cwd)));
