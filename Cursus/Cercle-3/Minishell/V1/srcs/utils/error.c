/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:55:13 by marvin            #+#    #+#             */
/*   Updated: 2025/03/10 16:55:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

int	error_message(int error, char *str)
{
	if (error == ERROR_FD)
		ft_fprintf(1, "ERROR : %d\n", ERROR_FD);
	else if (error == ERROR_DIR)
		ft_fprintf(1, "cd: no such file or directory: %s", str);
	else if (error == ERROR_PWD)
		ft_fprintf(1, "ERROR : %d\n", ERROR_PWD);
	else if (error == ERROR_ENV)
		ft_fprintf(1, "ERROR : %d\n", ERROR_ENV);
	return (-1);
}