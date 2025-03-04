/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:07 by ttas              #+#    #+#             */
/*   Updated: 2025/02/24 17:10:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/Executor.h"

// Get the current working directory
// Find the "Minishell" substring in cwd
// No need to free str here since you're returning ret, and you won't use `str` anymore
void bi_pwd(void)
{
    char *cwd = getcwd(NULL, 0);

    ft_printf("%s\n", ft_strnstr(cwd, "Minishell", ft_strlen(cwd)));
	free(cwd);
}

