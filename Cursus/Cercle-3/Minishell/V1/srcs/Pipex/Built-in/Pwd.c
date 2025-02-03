/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:07 by ttas              #+#    #+#             */
/*   Updated: 2025/01/31 16:01:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/Executor.h"

void bi_pwd(void)
{
    // Get the current working directory
    char *cwd = getcwd(NULL, 0);

    // Find the "Minishell" substring in cwd
    ft_printf("%s\n", ft_strnstr(cwd, "Minishell", ft_strlen(cwd)));

    // No need to free str here since you're returning ret, and you won't use `str` anymore
	free(cwd);
}

// int main(void)
// {
// 	char *str;
// 	str = bi_pwd();
// 	printf("%s\n", str);
// 	return 0;
// }