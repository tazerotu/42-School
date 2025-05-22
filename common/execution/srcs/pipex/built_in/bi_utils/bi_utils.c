/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:59:24 by marvin            #+#    #+#             */
/*   Updated: 2025/05/19 20:59:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/executor.h"

int	free_pwd(char *pwd, char *str)
{
	if (pwd)
		free(pwd);
	error_message_exec(ERROR_DIR, str);
	return (127);
}