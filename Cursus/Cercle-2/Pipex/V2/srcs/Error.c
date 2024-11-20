/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:32:49 by ttas              #+#    #+#             */
/*   Updated: 2024/08/01 12:40:18 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Pipex.h"

void	error(int error)
{
	if (error == INVALID_INPUT)
		write(1, "Error, Invalid input", 20);
	if (error == INVALID_PATH)
		write(1, "Error, Invalid path", 19);
	if (error == EXECUTE_ERROR)
		write(1, "Error, Execution error", 22);
	if (error == HERE_DOC_ERROR)
		write(1, "Error, Here doc", 15);
	exit(1);
}