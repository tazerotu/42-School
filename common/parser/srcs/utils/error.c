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

#include "../../includes/parser.h"

int	error_message_parsing(int error, char *str)
{
	if (error == RET_MALLOC_ERR)
		ft_fprintf(2, "Malloc Error when %s.\n", str);
	else if (error == RET_SYNTAX_ERR)
		ft_fprintf(2, "Syntax Error when %s.\n", str);
	return (-1);
}
