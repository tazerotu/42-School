/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:05:07 by ttas              #+#    #+#             */
/*   Updated: 2025/03/11 09:52:35 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/executor.h"

// Get the current working directory
void	bi_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		ft_fprintf(1, "ERROR : %d", ERROR_PWD);
		return ;
	}
	ft_printf("%s\n", cwd);
	free(cwd);
}

// ft_printf("%s\n", ft_strnstr(cwd, "Minishell", ft_strlen(cwd)));
